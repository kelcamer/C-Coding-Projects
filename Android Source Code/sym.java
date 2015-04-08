package remaclek.kelcamer.luciddreamkit;

/**
 * Created by Kelsey on 1/22/2015.
 */



        import android.annotation.TargetApi;
        import android.app.Activity;
        import android.graphics.Color;
        import android.os.Build;
        import android.os.Bundle;
        import android.os.CountDownTimer;
        import android.support.v4.app.NavUtils;
        import android.view.Gravity;
        import android.view.MenuItem;
        import android.view.View;
        import android.view.View.OnClickListener;
        import android.webkit.WebView;
        import android.webkit.WebViewClient;
        import android.widget.Button;
        import android.widget.TextView;
        import android.widget.Toast;

public class sym extends Activity implements OnClickListener {
    static CountDownTimer timer =null;
    Toast toast;
    int state = 1;

    @Override
	/*  All subclasses of Activity must implement the onCreate() method.
	 *  The system calls this when creating a new instance of the activity.
	 *  This method is where you must define the activity layout
	 *  with the setContentView() method and is where you should
	 *  perform initial setup for the activity components.
	 */

    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);



        WebView webView4;


        setContentView(R.layout.symbols);

        webView4 = (WebView) findViewById(R.id.symbol);
        webView4.loadUrl("http://www.worldofdreamsymbols.com/dream-dictionary.html");
        webView4.setWebViewClient(new WebViewClient());
        webView4.getSettings().setBuiltInZoomControls(true);
        webView4.getSettings().setUseWideViewPort(true);




        Button buttoast = (Button)findViewById(R.id.showToast);
        buttoast.setOnClickListener(listen);

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

    public void toast_timer(int time, String message){

        toast = new Toast(this);
        TextView textView=new TextView(this);
        textView.setTextColor(Color.WHITE);
        textView.setBackgroundColor(Color.BLACK);
        textView.setTextSize(14);
        textView.setText(message);
        toast.setGravity(Gravity.CENTER_VERTICAL, 0, 0);

        toast.setView(textView);


        timer =new CountDownTimer(time, 1000)
        {


            public void onTick(long millisUntilFinished)
            {
                toast.show();
                state = 3;
            }
            public void onFinish()
            {
                toast.cancel();

            }

        }.start();


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

            if(v==findViewById(R.id.showToast) && state == 1)
            {
                String message = getText(R.string.symbols).toString();
                toast_timer(20000, message);
            }
            else if(v==findViewById(R.id.showToast) && state == 3)
            {
                timer.cancel();
                state = 1;
            }

        }
    };

    @Override
    public void onClick(View v) {
        // TODO Auto-generated method stub

    }

}

