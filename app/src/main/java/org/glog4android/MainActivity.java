package org.glog4android;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    static {

        System.loadLibrary("mylog");

    }
    public native int init();
    public native int startLog();
    public native int shutDown();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        init();
       findViewById(R.id.button).setOnClickListener(this);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        shutDown();
    }

    @Override
    public void onClick(View v) {
        startLog();
    }
}
