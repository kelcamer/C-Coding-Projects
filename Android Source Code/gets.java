package remaclek.kelcamer.luciddreamkit;

/**
 * Created by Kelsey on 1/22/2015.
 */





        import android.annotation.TargetApi;
        import android.app.Activity;
        import android.os.Build;
        import android.os.Bundle;
        import android.support.v4.app.NavUtils;
        import android.text.method.ScrollingMovementMethod;
        import android.view.MenuItem;
        import android.widget.TextView;

public class gets extends Activity {

    @Override
	/*  All subclasses of Activity must implement the onCreate() method.
	 *  The system calls this when creating a new instance of the activity.
	 *  This method is where you must define the activity layout
	 *  with the setContentView() method and is where you should
	 *  perform initial setup for the activity components.
	 */
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);





        setContentView(R.layout.readit);
        TextView textView = (TextView)findViewById(R.id.pages);
        //textView.setTextSize(20);
        textView.setMovementMethod(new ScrollingMovementMethod());

        textView.setText(functions.readFromFile());

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

}
