#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define  BUFFER_SIZE  70
#define  TRUE          1
#define  FALSE         0

// initializes main array called img, and other variables including main output file
int**  img;
int** img2;
int    numRows;
int    numCols;
int** temppicx, temppicy;
int**  img,sobelout;
int    maxVal;
FILE*  fo1;

// defines functions
void addtopixels(int** imgtemp, int value);
// takes in function and value to change pixallation.
void  writeoutpic(char* fileName, int** imgtemp);
// takes in file name and changed image array and writes to a file
int** readpic(char* fileName);
// takes in file name to read image file (int array)
void  readHeader(FILE* imgFin);

int value = 42;
int   isComment(char* line);
void  readImgID(char* line);
void  readImgSize(char* line);
void  readMaxVal(char* line);
int** setImage();
void  readBinaryData(FILE* imgFin, int** imgtemp);

int main()
{
	
	int useript;

        char fileName[BUFFER_SIZE];
        char fileName2[BUFFER_SIZE];
        int i,j,rows,cols;
        char ci;


		printf("Type 1 to change the pixalation, type 2 to subtract from two pictures, or type 3 to highlight the edges of the picture.\n");
		scanf("%d", &useript);
		
		
		if(useript == 1){
		
		// Takes in image filename
        printf("Enter image1 filename: ");
        scanf("%s", fileName);

		// sets the 2D array img to the different pixal data from the filename
        img = readpic(fileName);

	    printf("Successfully read image file '%s'\n", fileName);
	    
	    

		// My own work - Kelsey Cameron
	
		printf("Enter pixal changes.  Use negative numbers to make the image darker.\n");
		scanf("%d", &value);
	
		// end of my own work

		// makes picture brighter by adding pixels
        addtopixels(img,value);

		// gets file path
        printf("Enter image filename for output: ");
        scanf("%s", fileName);
        
        // creates a new file and stores int array and header info
        writeoutpic(fileName,img);
		}
		
		// Subtraction method
		else if(useript == 2){
			
			
			
			printf("Enter image1 filename: ");
       		scanf("%s", fileName);
        	img = readpic(fileName);
	    	printf("Successfully read image file '%s'\n", fileName);			
			printf("Enter image2 filename: ");
       		scanf("%s", fileName2);
       		img2 = readpic(fileName2);
			printf("Successfully read image file '%s'\n", fileName2);
			subtract_pic(img, img2);
			printf("Enter image filename for output: ");
   		    scanf("%s", fileName);
        
        // creates a new file and stores int array and header info
       		writeoutpic(fileName,img);
			
		}
		else if(useript == 3){
			
			
		 printf("Enter image1 filename: ");
        scanf("%s", fileName);

		// sets the 2D array img to the different pixal data from the filename
        img = readpic(fileName);

	    printf("Successfully read image file '%s'\n", fileName);
     	sobelout= setImage();

        temppicx= setImage();
        temppicy= setImage();

        sobelfunc(img,sobelout,temppicx,temppicy); 

        printf("Enter image filename for output: ");
        scanf("%s", fileName);

        writeoutpic(fileName,sobelout);
			
			
			
			
		}
		// releases previous data used by array processes, has to do with pointers presumably
        free(img);
        img = NULL;

		// return whether it worked or not.
        return(EXIT_SUCCESS);
}

void addtopixels(int** imgtemp, int value)
{  
	
		
	//	addtopixels(img, pix);
	
        int i,j;
        // Simply adds the number of pixals specified into the img array, causing it to appear brighter.
        for (i=0;i<numRows;i++)
        { for (j=0;j<numCols;j++)
                {
                  imgtemp[i][j] += value;
                }
        }
}
void subtract_pic(int** img1, int** img2){
	int i, j;
	for (i=0;i<numRows;i++)
        { for (j=0;j<numCols;j++)
                {
                  img1[i][j] = abs(img1[i][j] - img2[i][j]);
                }
        }
	
	
	
}
void writeoutpic(char* fileName, int** imgtemp)
{
        int i,j;
        char ci;
        FILE* fo1;
        
        // opens the image to be written, stores into fo1, if write fails say unable...
        if((fo1 = fopen(fileName, "wb")) == NULL)
        {
                printf("Unable to open out image file '%s'\n", fileName);
                exit(EXIT_FAILURE);
        }
		// fprintf presumably gives you data in the debugger
        fprintf(fo1,"P5\n");
        fprintf(fo1,"%d %d\n", numRows, numCols);
        fprintf(fo1,"255\n");

        for (i=0;i<numRows;i++)
        { for (j=0;j<numCols;j++)
                {
                  ci   =  (char) (imgtemp[i][j]);
                  fprintf(fo1,"%c", ci);
                }
        }
}




int** readpic(char* fileName)
{
		// Final image (array)
        FILE* imgFin;
        // temporary array used for process
        int** imgtemp;

		// open up the file and read it, and if imgFin does not contain an image, say unable to open
        if((imgFin = fopen(fileName, "rb")) == NULL)
        {
                printf("Unable to open image file '%s'\n", fileName);
                exit(EXIT_FAILURE);
        }

		// gets header data from image
        readHeader(imgFin);

		// sets image into temp image
        imgtemp  = setImage();

		
        readBinaryData(imgFin, imgtemp);
		// closes the image reader
        fclose(imgFin);
        
        return  imgtemp;

}

void readHeader(FILE* imgFin)
{
        int  haveReadImgID   = FALSE;
        int  haveReadImgSize = FALSE;
        int  haveReadMaxVal  = FALSE;
        char line[BUFFER_SIZE];

        while(!(haveReadImgID && haveReadImgSize && haveReadMaxVal))
        {
                fgets(line, BUFFER_SIZE, imgFin);

                if((strlen(line) == 0) || (strlen(line) == 1))
                        continue;

                if(isComment(line))
                        continue;

                if(!(haveReadImgID))
                {
                        readImgID(line);
                        haveReadImgID = TRUE;
                }
                else if(!(haveReadImgSize))
                {
                        readImgSize(line);
                        haveReadImgSize = TRUE;
                }
                else if(!(haveReadMaxVal))
                {
                        readMaxVal(line);
                        haveReadMaxVal = TRUE;
                }
        }

}

int isComment(char *line)
{
        if(line[0] == '#')
                return(TRUE);

        return(FALSE);
}

void readImgID(char* line)
{
        if(strcmp(line, "P5\n") != 0)
        {
                printf("Invalid image ID\n");
                exit(EXIT_FAILURE);
        }
}

void readImgSize(char* line)
{
        unsigned i;

        for(i = 0; i < strlen(line); ++i)
        {
                if(!((isdigit((int) line[i])) || (isspace((int) line[i]))))
                {
                        printf("Invalid image size\n");
                        exit(EXIT_FAILURE);
                }
        }

        sscanf(line, "%d %d", &numRows, &numCols);
}

void readMaxVal(char* line)
{
        unsigned i;

        for(i = 0; i < strlen(line); ++i)
        {
                if(!((isdigit((int) line[i])) || (isspace((int) line[i]))))
                {
                        printf("Invalid image max value\n");
                        exit(EXIT_FAILURE);
                }
        }

        maxVal = atoi(line);
}

int** setImage()
{
		
        int** imgtemp;
        // temporary empty image
        unsigned i;
        // can support both positive and negative numbers

        imgtemp = (int**) calloc(numRows, sizeof(int*));

        for(i = 0; i < numRows; ++i)
        {
                imgtemp[i] = (int*) calloc(numCols, sizeof(int));
        }
        return imgtemp;
}

void readBinaryData(FILE* imgFin, int** imgtemp)
{
		// unsigned means it supports negative numbers in an int variable
        unsigned  i;
        unsigned  j;
        for(i = 0; i < numRows; ++i)
        {
                for(j = 0; j < numCols; ++j)
                {
                            imgtemp[i][j] = 
                            fgetc(imgFin);
                }
        }
}
void sobelfunc(int** pic, int** edges, int** tempx, int** tempy){

        int maskx[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
        int masky[3][3] = {{1,2,1},{0,0,0},{-1,-2,-1}};
        int maxival;


        
 
        int i,j,p,q,mr,sum1,sum2;
        double threshold;
         

        mr = 1;


        for (i=mr;i<numRows-mr;i++)
        { for (j=mr;j<numCols-mr;j++)
          {
             sum1 = 0;
             sum2 = 0;
             for (p=-mr;p<=mr;p++)
             {
                for (q=-mr;q<=mr;q++)
                {
                   sum1 += pic[i+p][j+q] * maskx[p+mr][q+mr];
                   sum2 += pic[i+p][j+q] * masky[p+mr][q+mr];
                }
             }
             tempx[i][j] = sum1;
             tempy[i][j] = sum2;
          }
        }

        maxival = 0;
        for (i=mr;i<numRows-mr;i++)
        { for (j=mr;j<numCols-mr;j++)
          {
             edges[i][j]=(int) (sqrt((double)((tempx[i][j]*tempx[i][j]) +
                                      (tempy[i][j]*tempy[i][j]))));
             if (edges[i][j] > maxival)
                maxival = edges[i][j];

           }
        }



        for (i=0;i<numRows;i++)
          { for (j=0;j<numCols;j++)
            {
             edges[i][j] = ((edges[i][j]*1.0) / maxival) * 255;            
             
            }
          }
}

