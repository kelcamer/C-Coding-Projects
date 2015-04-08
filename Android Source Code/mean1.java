package remaclek.kelcamer.luciddreamkit;

/**
 * Created by Kelsey on 1/22/2015.
 */
        import android.annotation.TargetApi;
        import android.app.Activity;
        import android.os.Build;
        import android.os.Bundle;
        import android.support.v4.app.NavUtils;
        import android.view.MenuItem;
        import android.view.View;
        import android.view.View.OnClickListener;
        import android.webkit.WebView;
        import android.webkit.WebViewClient;
        import android.widget.Button;

public class mean1 extends Activity implements OnClickListener {


    /*  All subclasses of Activity must implement the onCreate() method.
     *  The system calls this when creating a new instance of the activity.
     *  This method is where you must define the activity layout
     *  with the setContentView() method and is where you should
     *  perform initial setup for the activity components.
     */
    public static String Url = "http://www.dreambible.com/";
    public static String UrlC[] = {"http://www.dreambible.com/","http://www.dreamdictionarynow.com/cat/dream-dictionary/","http://www.dreammoods.com/dreamdictionary/", "http://www.edreaminterpretation.com/", "http://www.dreamdictionary.org/", "http://www.experienceproject.com/dream-dictionary/", "http://psychology.about.com/od/statesofconsciousness/p/dream-interpret.htm", "http://www.whats-your-sign.com/dream-meaning-common.html"};

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.meaning);

        WebView webView2 = (WebView) findViewById(R.id.meaning2);
        webView2.setWebViewClient(new WebViewClient());
        webView2.getSettings().setBuiltInZoomControls(true);
        webView2.getSettings().setUseWideViewPort(true);

        webView2.loadUrl(UrlC[0]);

        Button next = (Button)findViewById(R.id.next);
        next.setOnClickListener(listen);
        Button prev = (Button)findViewById(R.id.prev);
        prev.setOnClickListener(listen);

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

            if(v==findViewById(R.id.next)){

                WebView webView2 = (WebView) findViewById(R.id.meaning2);
                webView2.setWebViewClient(new WebViewClient());
                webView2.getSettings().setBuiltInZoomControls(true);
                webView2.getSettings().setUseWideViewPort(true);


                webView2.loadUrl(getUrl());
            }
            else if(v==findViewById(R.id.prev)){
                WebView webView2 = (WebView) findViewById(R.id.meaning2);
                webView2.setWebViewClient(new WebViewClient());
                webView2.getSettings().setBuiltInZoomControls(true);
                webView2.getSettings().setUseWideViewPort(true);


                webView2.loadUrl(getUrlback());


            }


        }
    };

    @Override
    public void onClick(View v) {
        // TODO Auto-generated method stub

    }
    public static String getUrl(){
        if (UrlC[0].equals(Url)){

            Url = UrlC[1];
        }
        else if (UrlC[1].equals(Url)){

            Url = UrlC[2];
        }
        else if (UrlC[2].equals(Url)){

            Url = UrlC[3];

        }
        else if (UrlC[3].equals(Url)){

            Url = UrlC[4];

        }
        else if (UrlC[4].equals(Url)){

            Url = UrlC[5];

        }
        else if (UrlC[5].equals(Url)){

            Url = UrlC[6];

        }
        else if (UrlC[6].equals(Url)){

            Url = UrlC[7];

        }
        else if (UrlC[7].equals(Url)){

            Url = UrlC[0];

        }

        return Url;

    }
    public static String getUrlback(){
        if (UrlC[7].equals(Url)){

            Url = UrlC[6];
        }
        else if (UrlC[6].equals(Url)){

            Url = UrlC[5];
        }
        else if (UrlC[5].equals(Url)){

            Url = UrlC[4];

        }
        else if (UrlC[4].equals(Url)){

            Url = UrlC[3];

        }
        else if (UrlC[3].equals(Url)){

            Url = UrlC[2];

        }
        else if (UrlC[2].equals(Url)){

            Url = UrlC[1];

        }
        else if (UrlC[1].equals(Url)){

            Url = UrlC[0];

        }
        else if (UrlC[0].equals(Url)){

            Url = UrlC[7];

        }

        return Url;

    }
}

