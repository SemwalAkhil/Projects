package com.example.bithdaycard

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.Image
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.bithdaycard.ui.theme.BithdayCardTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            BithdayCardTheme {
                Surface (
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colorScheme.background,
                ){
                    BirthdayImage();
                }
            }
        }
    }
}


/*
COMPOSABLE FUNCTIONS
The compose function that returns nothing and bears the @Composable annotation MUST be named using Pascal case. Pascal case refers to a naming convention in which the first letter of each word in a compound word is capitalized. The difference between Pascal case and camel case is that all words in Pascal case are capitalized. In camel case, the first word can be in either case.

The Compose function:

-> MUST be a noun: DoneButton()
-> NOT a verb or verb phrase: DrawTextField()
-> NOT a nouned preposition: TextFieldWithLink()
-> NOT an adjective: Bright()
-> NOT an adverb: Outside()
-> Nouns MAY be prefixed by descriptive adjectives: RoundIcon()

The composable function must provide default values for any parameters to preview it. For this reason, it is recommended not to preview the Greeting() function directly. Instead, you need to add another function, the BirthdayCardPreview() function in this case, that calls the Greeting() function with an appropriate parameter.
 */


@Preview(showBackground = true)
@Composable
fun BirthdayGreetingPreview() {
    BithdayCardTheme {
        // It is a good practice to pass the modifier attribute(s) along with the modifier from the parent composable. Update the modifier parameter in the GreetingText() as follows:
        BirthdayImage(modifier = Modifier)
    }
}

@Composable
fun BirthdayGreeting(name: String,from:String) {
    Column (
        //  It is a good practice to use padding values in increments of 4.dp.
        verticalArrangement = Arrangement.Center,
        modifier = Modifier
            .fillMaxSize()
    ) {
        Text(
            text = "Happy Birthday $name!",
            letterSpacing = (-5).sp,
            fontSize = 100.sp,
            textAlign = TextAlign.Center,
            /*
            Scalable pixels
    The scalable pixels (SP) is a unit of measure for the font size. UI elements in Android apps use two different units of measurement: density-independent pixels (DP), which you use later for the layout, and scalable pixels (SP). By default, the SP unit is the same size as the DP unit, but it resizes based on the user's preferred text size under phone settings.

            Note: The sp is an extension property for Int, which creates an sp unit. Similarly, you can use the .sp extension property in other data types, like Float and Double.
            */
            lineHeight = 100.sp,
        )
        Text(
            text = "From $from",
            fontSize = 50.sp,
            lineHeight = 50.sp,
            modifier = Modifier
                .padding(16.dp)
                .align(alignment = Alignment.CenterHorizontally),
        )
    }
}
@Composable
fun BirthdayImage(modifier: Modifier = Modifier){
    val image = painterResource(id = R.drawable.androidparty);
    Box (modifier){
        Image(
            painter = image,
            contentDescription = null,
            modifier = modifier.align(Alignment.Center),
            contentScale = ContentScale.Crop,
            alpha = 0.8F
        )
        BirthdayGreeting(name = "Android",from = "IOS");
    }
}