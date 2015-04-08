package remaclek.kelcamer.luciddreamkit;

/**
 * Created by Kelsey on 1/22/2015.
 */
        import java.io.BufferedInputStream;
        import java.io.BufferedReader;
        import java.io.BufferedWriter;
        import java.io.File;
        import java.io.FileInputStream;
        import java.io.FileNotFoundException;
        import java.io.FileWriter;
        import java.io.IOException;
        import java.io.InputStreamReader;
        import java.util.Calendar;

        import android.content.Context;
        import android.os.Environment;
        import android.util.Log;
        import android.widget.Toast;

//        import com.google.android.youtube.player.YouTubeInitializationResult;
 //       import com.google.android.youtube.player.YouTubePlayer;
  //      import com.google.android.youtube.player.YouTubePlayer.Provider;

public class functions {



    public static String getDate(){
        String mydate = java.text.DateFormat.getDateTimeInstance().format(Calendar.getInstance().getTime());
        return mydate;

    }
    public static void customToast(Context ctx, String message, int time){
        final Toast toast = Toast.makeText(ctx, message, Toast.LENGTH_SHORT);

        toast.show();



    }
    public static void generateNoteOnSD(String sFileName, String sBody) throws IOException{

        File root = new File(Environment.getExternalStorageDirectory(), "My Dreams");
        if (!root.exists()) {
            root.mkdirs();
        }


        File gpxfile = new File(root, sFileName);
        BufferedWriter writer = new BufferedWriter(new FileWriter(gpxfile,true));

        String newline = "                                   ";
        writer.write(getDate() + newline + newline + newline + "\r\n\r\n");
        writer.write(newline);

        writer.write(sBody + newline + newline + newline+ "\r\n\r\n");

        writer.flush();
        writer.close();



    }
    public static void smallText(Context context, CharSequence string){
        //Context context = getApplicationContext();
        Toast toast = Toast.makeText(context, string, Toast.LENGTH_LONG);
        toast.show();
    }
    static String readFromFile() {

        String ret = "";

        try {
            File root = new File(Environment.getExternalStorageDirectory(), "My Dreams");
            File gpxfile = new File(root, Main.fileName1);
            BufferedInputStream buf = new BufferedInputStream(new FileInputStream(gpxfile));

            if ( buf != null ) {
                InputStreamReader inputStreamReader = new InputStreamReader(buf);
                BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
                String receiveString = "";
                StringBuilder stringBuilder = new StringBuilder();

                while ( (receiveString = bufferedReader.readLine()) != null ) {
                    stringBuilder.append(receiveString);
                }

                buf.close();
                ret = stringBuilder.toString();
            }
        }
        catch (FileNotFoundException e) {
            Log.e("login activity", "File not found: " + e.toString());
        } catch (IOException e) {
            Log.e("login activity", "Can not read file: " + e.toString());
        }

        return ret;
    }

/*
public void string_activity(View button, String message){

	//String test = "Hello World";
	//intent.putExtra(EXTRA_MESSAGE, test);
	Intent intent = new Intent(Main.this, journal.class);
	name = message;

	startActivity(intent);



}
*/

/*

    public void onInitializationFailure(Provider arg0,
                                        YouTubeInitializationResult arg1) {
        // TODO Auto-generated method stub

    }
    public void onInitializationSuccess(Provider arg0, YouTubePlayer arg1,
                                        boolean arg2) {
        // TODO Auto-generated method stub


    }
  */
}
