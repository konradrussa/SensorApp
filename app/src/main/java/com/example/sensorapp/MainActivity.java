package com.example.sensorapp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;
import org.opencv.core.Core;
import com.example.sensorapp.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'sensorapp' library on application startup.
    static {
        System.loadLibrary("sensorapp");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        String message = "OpenCV: " + Core.NATIVE_LIBRARY_NAME + "\n";
        tv.setText(message + stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'sensorapp' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}