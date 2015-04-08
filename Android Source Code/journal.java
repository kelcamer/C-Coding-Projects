package remaclek.kelcamer.luciddreamkit;

/**
 * Created by Kelsey on 1/22/2015.
 */
        import android.annotation.TargetApi;
        import android.app.Activity;
        import android.content.Intent;
        import android.os.Build;
        import android.os.Bundle;
        import android.support.v4.app.NavUtils;
        import android.view.MenuItem;
        import android.view.View;
        import android.view.View.OnClickListener;
        import android.widget.TextView;

public class journal extends Activity implements OnClickListener {

    @Override
	/*  All subclasses of Activity must implement the onCreate() method.
	 *  The system calls this when creating a new instance of the activity.
	 *  This method is where you must define the activity layout
	 *  with the setContentView() method and is where you should
	 *  perform initial setup for the activity components.
	 */

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);


        // Get the message from the intent
        // Why would I ever want another intent? :P
        //Intent intent = getIntent();
        //String message = intent.getStringExtra(Main.EXTRA_MESSAGE);
        //textView.setText("This is your message: " + message);
        // Create the text view
        setContentView(R.layout.realitycheck);
        TextView textView = (TextView)findViewById(R.id.checks4);

        textView.setTextSize(20);

        textView.setText(Main.name);


		/*TextView textView = new TextView(this);
		textView.setTextSize(20);

		textView.setText(Main.name);
		setContentView(textView);












		/*for (int x = 0; x < 10; x++){
		textView.setText(message);

		}

		*/


        // Set the text view as the activity layout


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


    public void showJ(View button, String message){

        //String test = "Hello World";
        //intent.putExtra(EXTRA_MESSAGE, test);
        Intent intent = new Intent(journal.this, gets.class);
        Main.name = message;

        startActivity(intent);



    }

    @Override
    public void onClick(View v) {
        // TODO Auto-generated method stub

    }

}
