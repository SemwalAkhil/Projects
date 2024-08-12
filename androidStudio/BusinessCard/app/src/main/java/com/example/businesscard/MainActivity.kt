package com.example.businesscard

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.Image
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.businesscard.ui.theme.BusinessCardTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            BusinessCardTheme {
                DisplayFunc()
            }
        }
    }
}

@Composable
fun DisplayFunc() {
    val image = painterResource(id = R.drawable.android_logo)
    Column(modifier = Modifier.background(color = Color(0xFFB2D8D8)).fillMaxSize(), horizontalAlignment = Alignment.CenterHorizontally, verticalArrangement = Arrangement.Center) {
        Image(painter = image, contentDescription = "Android Logo", modifier = Modifier.background(color = Color(0xFF004C4C)).size(150.dp))
        Text(text="Jennifer Doe",fontSize=48.sp, textAlign = TextAlign.Center)
        Text(text="Android Developer Extraordinaire", textAlign = TextAlign.Center, color = Color(0xFF008080))
        Box{
            Column(modifier = Modifier.padding(top = 400.dp)) {
                Row (modifier = Modifier.height(30.dp)){
                    Image(painter = painterResource(id = R.drawable.baseline_call_24), contentDescription = "Call")
                    Text(text="+11 (123) 444 555 666", modifier = Modifier.padding(start = 20.dp))
                }
                Row (modifier = Modifier.height(30.dp)){
                    Image(painter = painterResource(id = R.drawable.baseline_share_24), contentDescription = "Share")
                    Text(text="@AndroidDev", modifier = Modifier.padding(start = 20.dp))
                }
                Row (modifier = Modifier.height(30.dp)){
                    Image(painter = painterResource(id = R.drawable.baseline_mail_24), contentDescription = "Email")
                    Text(text="jdoe@example.com", modifier = Modifier.padding(start = 20.dp))
                }
            }
        }
    }

}
@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    BusinessCardTheme {
        DisplayFunc()
    }
}