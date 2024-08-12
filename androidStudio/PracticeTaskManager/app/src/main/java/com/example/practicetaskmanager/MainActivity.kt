package com.example.practicetaskmanager

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.practicetaskmanager.ui.theme.PracticeTaskManagerTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            PracticeTaskManagerTheme {
                Scaffold(modifier = Modifier.fillMaxSize()) { innerPadding ->
                    DisplayFun(modifier = Modifier.padding(innerPadding))
                }
            }
        }
    }
}

@Composable
@Preview (showBackground = true)
fun DefaultPreview(modifier: Modifier = Modifier) {
    DisplayFun()
}

@Composable
fun DisplayFun(modifier: Modifier = Modifier){
    val msg1 = "All tasks completed"
    val msg2 = "Nice work!"
    Column(modifier = modifier.fillMaxSize(),verticalArrangement = Arrangement.Center, horizontalAlignment = Alignment.CenterHorizontally){
        ImageFun()
        TextFun(msg1,true)
        TextFun(msg2)
    }
}

@Composable
fun ImageFun(){
    val painter = painterResource(id = R.drawable.ic_task_completed)
    Image(painter = painter, contentDescription = "Task Completed")
}
@Composable
fun TextFun(message: String,head:Boolean = false){
    if(head){
        Text(message, modifier = Modifier.padding(top= 24.dp, bottom = 8.dp), fontWeight = FontWeight.Bold)
    }
    else{
        Text(message, fontSize = 16.sp)
    }

}