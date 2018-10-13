package com.chillguy.footballsubmission1final

import android.graphics.Typeface
import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import android.view.Gravity
import android.widget.LinearLayout
import com.bumptech.glide.Glide
import org.jetbrains.anko.*

class DetailItemActivity : AppCompatActivity() {

    private var name: String = ""

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        linearLayout {
            //tools:context = .DetailItem //not support attribute
            linearLayout {
                orientation = LinearLayout.VERTICAL
                imageView {
                    val intent = intent
                    Glide.with(context).load(intent.getIntExtra("pict", 0)).into(this)
                    //app:layout_constraintBottom_toBottomOf = parent //not support attribute
                    //app:layout_constraintEnd_toEndOf = parent //not support attribute
                    //app:layout_constraintStart_toStartOf = parent //not support attribute
                    //app:layout_constraintTop_toTopOf = parent //not support attribute
                    //app:layout_constraintVertical_bias = 0.0 //not support attribute
                    //app:srcCompat = @drawable/img_barca //not support attribute
                }.lparams(width = dip(200), height = dip(200)) {
                    gravity = Gravity.CENTER_HORIZONTAL
                }
                textView {
                    text =   getString(R.string.default_text)
                    typeface = Typeface.DEFAULT_BOLD
                    val intent = intent
                   name = intent.getStringExtra("name")
                    text = name
                    //app:layout_constraintTop_toBottomOf = @+id/detail_gambar //not support attribute
                    //tools:layout_editor_absoluteX = 163dp //not support attribute
                }.lparams(width = matchParent) {
                    gravity = Gravity.CENTER_HORIZONTAL
                    marginEnd = dip(8)
                    marginStart = dip(8)
                    topMargin = dip(24)
                }
                textView {
                    text = getString(R.string.default_text)
                    val intent = intent
                    name = intent.getStringExtra("desc")
                    text = name
                    //app:layout_constraintEnd_toEndOf = parent //not support attribute
                    //app:layout_constraintStart_toStartOf = parent //not support attribute
                    //app:layout_constraintTop_toBottomOf = @+id/nama_club //not support attribute
                }.lparams(width = matchParent) {
                    gravity = Gravity.CENTER_HORIZONTAL
                    marginEnd = dip(8)
                    marginStart = dip(8)
                    topMargin = dip(24)
                }
            }.lparams(width = matchParent, height = matchParent) {
                margin = dip(20)
            }
        }
    }
 }