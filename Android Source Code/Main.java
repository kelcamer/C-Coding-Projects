package remaclek.kelcamer.luciddreamkit;





import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
//import com.google.


public class Main extends Activity implements OnClickListener {
    public final static String EXTRA_MESSAGE = "com.kelcamer.remacleck.MESSAGE";
    public static String name;

    public static String message;
    public static String fileName1 = "dream_journal";
    public static String message2;

    public static StringBuilder text = new StringBuilder();
    //public static View main;
    // Creates a textview and stores the data from the xml file into it



    // puts the data in the textview into a string called message

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);




        // Here I am defining all the buttons from the xml file to be able to reference
        // them with their respective names.   I also grabbed the header string just because.  After all, Why not?


        Button check = (Button)findViewById(R.id.check);
        Button journal = (Button)findViewById(R.id.journal);
        Button symbol = (Button)findViewById(R.id.symbol);
        Button beat = (Button)findViewById(R.id.beat);
        Button meaning = (Button)findViewById(R.id.mean);



        // Sets the onClick function for each button
        check.setOnClickListener(listen);
        journal.setOnClickListener(listen);
        symbol.setOnClickListener(listen);
        beat.setOnClickListener(listen);
        meaning.setOnClickListener(listen);


    }





    OnClickListener listen = new OnClickListener(){
        @Override
        public void onClick(View v) {


            // First button
            if(v == findViewById(R.id.check)){

                showChe(v);

            }
            // Second Button
            else if(v==findViewById(R.id.journal)){

                journalSplash(v);

            }
            // Third Button
            else if(v==findViewById(R.id.symbol)){
                symbol(v);
            }


            // Fourth button.  This one is complex.
            else if(v==findViewById(R.id.beat)){

                Intent intent = new Intent(Main.this,Beat.class);
                startActivity(intent);

            }


            // Fifth Button
            else if(v==findViewById(R.id.mean))
            {
                findMeaning(v);
            }


        }


    };

    @Override
    public void onClick(View v) {
        // TODO Auto-generated method stub
        // Do not delete me!

    }

    public void showChe(View v){

        Intent intent = new Intent(Main.this, showc.class);
        startActivity(intent);


    }
    public void journalSplash(View v){
        Intent intent = new Intent(Main.this, jour1.class);
        startActivity(intent);


    }
    public void symbol(View v){
        Intent intent = new Intent(Main.this, sym.class);
        startActivity(intent);

    }
    public void findMeaning(View v){
        Intent intent = new Intent(Main.this, mean1.class);
        startActivity(intent);

    }

}




/*
 * 
 * 
 * IMPORTANT NOTES APP DEVELOPERS MUST NEVER FORGET
 * 
 * 1.  Checking for the new view must be in a different if statement, or in the onClick function in a different activity.
 * 2.  You only need to initialize the new button in the previous view.
 * 3.  Put in manifest for Youtube vids:		<uses-library android:name="com.google.android.youtube" />
 * 4.  YouTube API Key:   AIzaSyATS-AG8rEnlKY5lzUkJZ7cq3F_mgcDdwU
 * 5.  If there is a Dalvik error, first check to make sure you aren't accidentally passing in a view, then check to make sure 
 * ar
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
