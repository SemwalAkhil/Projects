package com.example.practicecomposearticle

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.practicecomposearticle.ui.theme.PracticeComposeArticleTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            PracticeComposeArticleTheme {
                Scaffold(modifier = Modifier.fillMaxSize()) { innerPadding ->
                    DisplayFun(message = "Android",modifier = Modifier.padding(innerPadding));
                }
            }
        }
    }
}

@Composable
@Preview(showBackground = true)
fun AppPreview() {
    PracticeComposeArticleTheme {
        DisplayFun(message = "Android")
    }
}
@Composable
fun DisplayFun(message: String, modifier: Modifier = Modifier) {
    Column(modifier = modifier) {
        ImageFun(modifier = modifier);
        TextFun(message = stringResource(R.string.msg1),heading = true);
        TextFun(message = stringResource(R.string.msg2))
        TextFun(message = stringResource(R.string.msg3))
    }

}
@Composable
fun TextFun(message: String,heading: Boolean = false) {
    if (!heading){
        Text(text = message, modifier = Modifier.padding(top = 16.dp, start = 16.dp, end = 16.dp), textAlign = TextAlign.Justify);
    } else {
        Text(text = message, style = MaterialTheme.typography.headlineLarge, fontSize = 24.sp, lineHeight = 28.sp, modifier = Modifier.padding(top = 16.dp, start = 16.dp, end = 16.dp));
    }

}
@Composable
fun ImageFun(modifier: Modifier = Modifier) {
    Image(painter = painterResource(id = R.drawable.bg_compose_background), contentDescription = null);
}