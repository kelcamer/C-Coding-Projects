package remaclek.kelcamer.luciddreamkit;


import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;

import java.net.URI;
import java.security.Provider;
import java.util.Arrays;
import java.util.List;

// * Created by Kelsey on 1/22/2015.
public class Beat extends Activity {
    static private final String DEVELOPER_KEY = "AIzaSyATS-AG8rEnlKY5lzUkJZ7cq3F_mgcDdwU";
    public static String VIDEO = "PbRoUSW6f2o";
    public static String Vid[] = {"PbRoUSW6f2o", "SXAA9Jtobsk", "4XxHi1Ons3o", "zWhOr--5kSA"};


    public static List<String> vidList = Arrays.asList(Vid);
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
      //  setContentView(R.layout.beat);
        // changes to xml file named beat
        // initializes the video. :3 :3 :3 YAYYYYYYYYYYYYYYYYY!

       // YouTubePlayerView yt2 = (YouTubePlayerView)findViewById(R.id.youtube_view2);

        //yt2.initialize(DEVELOPER_KEY, this);

        startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("http://www.youtube.com/watch?v=" + Vid[0])));
        functions.customToast(getApplicationContext(), "Video should run", 10000);

        }
   // public void onInitializationSuccess(Provider provider, YouTubePlayer player,
                                    //    boolean wasRestored)

    //{
        // player.loadVideo(VIDEO);
//        player.setPlayerStyle(YouTubePlayer.PlayerStyle.DEFAULT);
        //      player.cueVideos(vidList);
        //    player.play();
        // player.loadVideo(Main.getVideo());

        //  }


        /**
         * Set up the {@link android.app.ActionBar}, if the API is available.
         */
  /*  @TargetApi(Build.VERSION_CODES.HONEYCOMB)
    private void setupActionBar() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB) {
            getActionBar().setDisplayHomeAsUpEnabled(true);
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.beat, menu);
        return true;
    }*/
/*
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
*/
//    @Override
        //   public void onClick(View arg0) {
        // TODO Auto-generated method stub

        // }

        //@Override
        //public void onInitializationFailure(Provider arg0,
        //                                  YouTubeInitializationResult arg1) {
        // TODO Auto-generated method stub

        //}


//}

}