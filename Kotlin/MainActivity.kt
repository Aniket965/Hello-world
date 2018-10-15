package com.chillguy.footballsubmission1final

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import android.support.v7.widget.LinearLayoutManager
import com.chillguy.footballsubmission1final.R.array.*
import com.chillguy.footballsubmission1final.R.layout.activity_main
import kotlinx.android.synthetic.main.activity_main.*
import org.jetbrains.anko.startActivity

class MainActivity : AppCompatActivity() {

    private var items: MutableList<Item> = mutableListOf()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(activity_main)
        initData()

        // Memasukkan tipe anakan layout ke induk layout
        club_list.layoutManager = LinearLayoutManager(this)
        // Biar bisa ditampilkan di Recycle View dan bisa di klik pindah halaman
        club_list.adapter = RecyclerViewAdapter(items) {
            startActivity<DetailItemActivity>("name" to it.name, "desc" to it.desc, "pict" to it.image)
        }
    }

    private fun initData() {
        val name = resources.getStringArray(club_name)
        val image = resources.obtainTypedArray(club_image)
        val desc = resources.getStringArray(club_desc)
        items.clear()
        for (i in name.indices) {
            items.add(Item(name[i], image.getResourceId(i, 0),desc[i]))
        }

        //Recycle the typed array
        image.recycle()
    }
}
