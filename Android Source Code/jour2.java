package remaclek.kelcamer.luciddreamkit;

/**
 * Created by Kelsey on 1/22/2015.
 */

        import java.io.BufferedWriter;
        import java.io.File;
        import java.io.FileWriter;
        import java.io.IOException;

        import android.annotation.TargetApi;
        import android.app.Activity;
        import android.content.Intent;
        import android.os.Build;
        import android.os.Bundle;
        import android.os.Environment;
        import android.support.v4.app.NavUtils;
        import android.view.MenuItem;
        import android.view.View;
        import android.view.View.OnClickListener;
        import android.widget.Button;
        import android.widget.EditText;
        import android.widget.ImageButton;
        import android.widget.Toast;

public class jour2 extends Activity implements OnClickListener {
    String sbody_public = "";
    @Override
	/*  All subclasses of Activity must implement the onCreate() method.
	 *  The system calls this when creating a new instance of the activity.
	 *  This method is where you must define the activity layout
	 *  with the setContentView() method and is where you should
	 *  perform initial setup for the activity components.
	 */

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.newdream);
        Button submit = (Button)findViewById(R.id.submitdream);
        submit.setOnClickListener(listen);
        Button open = (Button)findViewById(R.id.readmyj);
        open.setOnClickListener(listen);
        ImageButton share = (ImageButton)findViewById(R.id.share);
        share.setOnClickListener(listen);
        ImageButton share2 = (ImageButton)findViewById(R.id.share2);
        share2.setOnClickListener(listen);
    }


    /**
     * Set up the {@link android.app.ActionBar}, if the API is available.
     */
    @TargetApi(Build.VERSION_CODES.HONEYCOMB)
    private void setupActionBar() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB) {
            getActionBar().setDisplayHomeAsUpEnabled(true);
        }
    }


    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case android.R.id.home:
                // This ID represents the Home or Up button. In the case of this
                // activity, the Up button is shown. Use NavUtils to allow users
                // to navigate up one level in the application structure. For
                // more details, see the Navigation pattern on Android Design:
                //
                // http://developer.android.com/design/patterns/navigation.html#up-vs-back
                //
                NavUtils.navigateUpFromSameTask(this);
                return true;
        }
        return super.onOptionsItemSelected(item);
    }


    OnClickListener listen = new OnClickListener(){
        @Override
        public void onClick(View v) {

            if(v==findViewById(R.id.submitdream)){

                EditText dream = (EditText)findViewById(R.id.input_dream);

                String message = dream.getText().toString();

                String fileName = Main.fileName1;


                try {
                    generateNoteOnSD(fileName, message);
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }

                dream.setText("");

            }
            else if(v==findViewById(R.id.readmyj)){


                //String dreamMessage = Main.readFromFile();

                showJ((Button)findViewById(R.id.readmyj), functions.readFromFile());

            }
            else if(v==findViewById(R.id.share)){

                shareNow((ImageButton)findViewById(R.id.share), functions.readFromFile());
            }
            else if(v==findViewById(R.id.share2)){

                shareNow((ImageButton)findViewById(R.id.share), sbody_public);

            }

        }
    };

    @Override
    public void onClick(View v) {
        // TODO Auto-generated method stub

    }
    public void generateNoteOnSD(String sFileName, String sBody) throws IOException{

        File root = new File(Environment.getExternalStorageDirectory(), "My Dreams");
        if (!root.exists()) {
            root.mkdirs();
        }


        File gpxfile = new File(root, sFileName);
        BufferedWriter writer = new BufferedWriter(new FileWriter(gpxfile,true));

        String newline = "                                   ";
        writer.write(functions.getDate() + newline + newline + newline + "\r\n\r\n");
        writer.write(newline);

        writer.write(sBody + newline + newline + newline+ "\r\n\r\n");

        writer.flush();
        writer.close();
        sbody_public = sBody;
        Toast.makeText(this, "Saved", Toast.LENGTH_SHORT).show();

    }

    public void shareNow(View button, String message){

        Intent intent = new Intent(jour2.this, Share.class);

        Main.name=message;
        startActivity(intent);

        //create the send intent



    }

    public void showJ(View button, String message){

        //String test = "Hello World";
        //intent.putExtra(EXTRA_MESSAGE, test);
        Intent intent = new Intent(jour2.this, gets.class);
        Main.name = message;

        startActivity(intent);



    }

}
