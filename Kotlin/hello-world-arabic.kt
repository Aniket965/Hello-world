package id.ac.undip.ce.student.muhammadrizqi.hellokotlin

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import kotlinx.android.synthetic.main.activity_main.*
import org.jetbrains.anko.toast

class HelloDonya : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        btn1.setOnClickListener {
            toast("مرحبا بالعالم")
            printButtonClickLog()
        }
    }

    private fun printButtonClickLog() {
        Log.i("مرحبا بالعالم", "klik btn1")
    }
}
