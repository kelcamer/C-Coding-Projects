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
        import android.widget.Button;
        import android.view.View.OnClickListener;
        import java.util.*;

public class showc extends Activity implements OnClickListener {



    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);



        setContentView(R.layout.showcheck);



        // Changes the screen to showcheck
        Button mouth = (Button)findViewById(R.id.mouth);
        Button jump = (Button)findViewById(R.id.jump);
        Button read = (Button)findViewById(R.id.read);
        Button mirror = (Button)findViewById(R.id.mirror);
        Button fly = (Button)findViewById(R.id.fly);
        Button magic = (Button)findViewById(R.id.magic);
        Button watch = (Button)findViewById(R.id.watch);
        Button palms = (Button)findViewById(R.id.palms);
        Button math = (Button)findViewById(R.id.math);
        Button vision = (Button)findViewById(R.id.vision);
        Button ask = (Button)findViewById(R.id.ask);
        Button induce = (Button)findViewById(R.id.induce);






        // Listens for the click.
        mouth.setOnClickListener(listen);
        jump.setOnClickListener(listen);
        read.setOnClickListener(listen);
        mirror.setOnClickListener(listen);
        fly.setOnClickListener(listen);
        magic.setOnClickListener(listen);
        watch.setOnClickListener(listen);
        palms.setOnClickListener(listen);
        math.setOnClickListener(listen);
        vision.setOnClickListener(listen);
        ask.setOnClickListener(listen);
        induce.setOnClickListener(listen);








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
public class Contact{
    String name;
    ArrayList<Integer> phone;
    ArrayList<String> email;
    ArrayList<String> address;
    String notes;
    String website;
    // constructor
    public Contact(String name2, ArrayList<Integer> phone2, ArrayList<String> email2, ArrayList<String> address2, String notes2, String website2){
        name = name2;
        phone = phone2;
        email = email2;
        notes = notes2;
        address = address2;
        website = website2;

    }

}
    public boolean isEqual(Contact contact1, Contact contact2){
       /*
       A contact is equal if and only if:
        1. The names of the contacts are exactly the same.
        Not the same last name only.  Same last and first.
        2. If at least one phone number matches
        3. If they have at least one of the same addresses?
        4. I don't think e-mail should be a valid basis for merging.
        */
        boolean flag = false;

        if(!contact1.name.equals(contact2.name)){
            flag = false;
                 }
        else {
            for (int count = 0; count < contact1.phone.size(); count++) {
                if ((contact1.phone.contains(contact2.phone.get(count))) ||
                    (contact1.address.contains(contact2.address.get(count)))) {
                    // Compare every number to every other number in the second contact.
                    // If at least one phone number or address matches one phone number or address
                    // in the second contact then they are equal
                    flag = true;

                }


            }

        }

        return flag;
    }
    // TODO: Only one address
 public Contact merge(Contact contact1, Contact contact2){
        Contact new_merged = contact1;
        // sets new contact to contact 1, to automatically grab data

        // If phone number is not already in there, add it
        if(!new_merged.phone.contains(contact2.phone))
        new_merged.phone.addAll(contact2.phone);
        // add new phone numbers in
        // If phone number is not already in there, add it
        if(!new_merged.address.contains(contact2.address))
        new_merged.address.addAll(contact2.address);
        // add new addresses in
        new_merged.notes += "\n" + contact2.notes;
        // append notes


    return new_merged;
 }
public List<Contact> matt_merging(List<Contact> total_contacts){
    // For each contact
    int current, next = 0;

    // Iterate through all contacts
    for(int count = 1; count <= total_contacts.size(); count++){

        current = count - 1;
        next = count;
        // if the current contact matches the one after it, and both contacts aren't null
         if(total_contacts.isEmpty() == false){
            // create an equal function that performs a series of checks to make sure contacts are identical
            // merge

           List<Contact> merged_contacts = new ArrayList<Contact>();
           List<Contact> remove_these = new ArrayList<Contact>();
           // creates a blank contact

            boolean isEquals = false;
            if(isEqual(total_contacts.get(current), total_contacts.get(next))){
                Contact new_contact = merge(total_contacts.get(current), total_contacts.get(next));
                merged_contacts.add(new_contact);
                remove_these.add(total_contacts.get(current));
                remove_these.add(total_contacts.get(next));
            }

                    // Quick Question.  What is your custom field, exactly?  Is it text?
        }
    }





}








    public void string_activity(View button, String message){

        //String test = "Hello World";
        //intent.putExtra(EXTRA_Main.message, test);
        Intent intent = new Intent(showc.this, journal.class);
        Main.name = Main.message;

        startActivity(intent);



    }




    OnClickListener listen = new OnClickListener(){
        @Override
        public void onClick(View v) {

            // TODO Auto-generated method stub
            if(v == findViewById(R.id.mouth)){

                // This code works.
                Main.message = getText(R.string.checkData1).toString();

                string_activity((Button)findViewById(R.id.mouth), Main.message);


            }
            else if(v == findViewById(R.id.jump)){

                // This code works.
                Main.message = getText(R.string.checkData2).toString();

                string_activity((Button)findViewById(R.id.jump), Main.message);


            }
            else if(v == findViewById(R.id.read)){

                // This code works.
                Main.message = getText(R.string.checkData3).toString();

                string_activity((Button)findViewById(R.id.jump), Main.message);


            }
            else if(v == findViewById(R.id.mirror)){

                // This code works.
                Main.message = getText(R.string.checkData4).toString();

                string_activity((Button)findViewById(R.id.mirror), Main.message);


            }
            else if(v == findViewById(R.id.fly)){

                // This code works.
                Main.message = getText(R.string.checkData5).toString();

                string_activity((Button)findViewById(R.id.fly), Main.message);


            }
            else if(v == findViewById(R.id.magic)){

                // This code works.
                Main.message = getText(R.string.checkData6).toString();

                string_activity((Button)findViewById(R.id.magic), Main.message);


            }
            else if(v == findViewById(R.id.watch)){

                // This code works.
                Main.message = getText(R.string.checkData7).toString();

                string_activity((Button)findViewById(R.id.watch), Main.message);


            }
            else if(v == findViewById(R.id.palms)){

                // This code works.
                Main.message = getText(R.string.checkData8).toString();

                string_activity((Button)findViewById(R.id.palms), Main.message);


            }
            else if(v == findViewById(R.id.math)){

                // This code works.
                Main.message = getText(R.string.checkData9).toString();

                string_activity((Button)findViewById(R.id.math), Main.message);


            }
            else if(v == findViewById(R.id.vision)){

                // This code works.
                Main.message = getText(R.string.checkData10).toString();

                string_activity((Button)findViewById(R.id.vision), Main.message);


            }
            else if(v == findViewById(R.id.ask)){

                // This code works.
                Main.message = getText(R.string.checkData11).toString();

                string_activity((Button)findViewById(R.id.ask), Main.message);


            }
            else if(v == findViewById(R.id.induce)){

                // This code works.
                Main.message = getText(R.string.checkData12).toString();

                string_activity((Button)findViewById(R.id.induce), Main.message);


            }
        }
    };

    @Override
    public void onClick(View v) {
        // TODO Auto-generated method stub

    }



}


/*
 *
 *
 * 		// TODO Auto-generated method stub

 *
 *
 *
 *
 */





/*
Old Code in Main;

            // gives new contact name of person
        // PREV    new_contact.name = total_contacts.get(next).name;

            // add all of the phone numbers in the int array list from both
            // current contact and one after it, and store in blank contact
             // PREV   new_contact.phone.addAll(total_contacts.get(next).phone);
              //PREV  new_contact.phone.addAll(total_contacts.get(current).phone);
            // do the same for emails
              //PREV  new_contact.email.addAll(total_contacts.get(next).email);
              //PREV  new_contact.email.addAll(total_contacts.get(current).email);
            // Append the notes together
              //PREV  new_contact.notes = total_contacts.get(next).notes + "\n" + total_contacts.get(current).notes;

                    // Delete both contacts in total contacts, and store new, merged, contact in there
                    //total_contacts.remove(count);
                    //total_contacts.remove(current);



 */



