package com.example.greetingcard

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.example.greetingcard.ui.theme.GreetingCardTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            // The setContent() function within the onCreate() function is used to define your layout through composable functions. All functions marked with the @Composable annotation can be called from the setContent() function or from other Composable functions. The annotation tells the Kotlin compiler that this function is used by Jetpack Compose to generate the UI.
            GreetingCardTheme {
                // A surface container using the 'background' color from the theme
                Surface(modifier = Modifier.fillMaxSize(), color = MaterialTheme.colorScheme.background) {
                    Greeting(
                        name = "Android"
                    )
                }
            }
        }
    }
}

@Composable
// Composable functions are like regular functions with a few differences: functions names are capitalized, you add the @Composable annotation before the function, @Composable functions can't return anything.
fun Greeting(name: String, modifier: Modifier = Modifier) {
    Surface(color = Color.Cyan) {
    //    To set a different background color for your introduction, you'll need to surround your text with a Surface. A Surface is a container that represents a section of UI where you can alter the appearance, such as the background color or border.
        Text(
            text = "Hello, this is $name!!!",
            modifier = modifier.padding(24.dp)
            // A Modifier is used to augment or decorate a composable. One modifier you can use is the padding modifier, which adds space around the element (in this case, adding space around the text). This is accomplished by using the Modifier.padding() function.
        )
    }
}

@Preview(showBackground = true)
// The GreetingPreview() function is a cool feature that lets you see what your composable looks like without having to build your entire app. To enable a preview of a composable, annotate with @Composable and @Preview. The @Preview annotation tells Android Studio that this composable should be shown in the design view of this file.

// Since Android Studio by default uses a light theme for the editor, it can be hard to see the difference between showBackground = true and showBackground = false
@Composable
fun GreetingPreview() {
    GreetingCardTheme {
        Greeting("Android")
    }
}