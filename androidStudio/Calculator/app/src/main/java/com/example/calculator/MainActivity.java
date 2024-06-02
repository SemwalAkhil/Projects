package com.example.calculator;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import com.google.android.material.snackbar.Snackbar;

public class MainActivity extends AppCompatActivity {

    public EditText editText;
    public EditText editText2;
    public Button button1;
    public Button button2;
    public Button button3;
    public Button button4;
    public Button button5;
    public Number solved = 0.0;
    public TextView textView;
    public TextView textView2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
        button1 = findViewById(R.id.button1);
        button2 = findViewById(R.id.button2);
        button3 = findViewById(R.id.button3);
        button4 = findViewById(R.id.button4);
        button5 = findViewById(R.id.button5);

        textView = findViewById(R.id.textView);
        textView.setText("");
        textView2 = findViewById(R.id.textView1);
        textView2.setText("0.0");
        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onButtonClick(button1);
            }
        });
        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onButtonClick(button2);
            }
        });
        button3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onButtonClick(button3);
            }
        });
        button4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onButtonClick(button4);
            }
        });
        button5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onButtonClick(button5);
            }
        });
    }
    public void onButtonClick(Button button) {
        editText = findViewById(R.id.editTextNumberDecimal);
        editText2 = findViewById(R.id.editTextNumberDecimal2);
        if (solved.doubleValue() != 0.0) {
            editText.setText(String.valueOf(solved));
        }
        if (editText.getText().toString().isEmpty() || editText2.getText().toString().isEmpty()) {
            Toast.makeText(this, "Please enter a number", Toast.LENGTH_SHORT).show();
            return;
        }
        textView.setText(button.getText().toString());
        if (button.getId() == R.id.button1) {
            solved = Double.parseDouble(String.valueOf(editText.getText())) + Double.parseDouble(String.valueOf(editText2.getText()));
        } else if (button.getId() == R.id.button2) {
            solved =
                    Double.parseDouble(String.valueOf(editText.getText())) - Double.parseDouble(String.valueOf(editText2.getText()));
        } else if (button.getId() == R.id.button3) {
            solved =
                    Double.parseDouble(String.valueOf(editText.getText())) * Double.parseDouble(String.valueOf(editText2.getText()));
        } else if (button.getId() == R.id.button4) {
            if (Double.parseDouble(String.valueOf(editText2.getText())) == 0) {
                Toast.makeText(this, "Cannot divide by zero", Toast.LENGTH_SHORT).show();
                return;
            }
            solved =
                    Double.parseDouble(String.valueOf(editText.getText())) / Double.parseDouble(String.valueOf(editText2.getText()));
        } else {
            solved = 0.0;
            textView.setText("");
            editText.setText("");
            editText2.setText("");
        }
//        Toast.makeText(this, String.valueOf(solved), Toast.LENGTH_SHORT).show();10
        textView2.setText(String.valueOf(solved));
    }
}