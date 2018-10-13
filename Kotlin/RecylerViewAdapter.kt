package com.chillguy.footballsubmission1final

import android.support.v7.widget.RecyclerView
import android.view.Gravity
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.LinearLayout
import android.widget.TextView
import com.bumptech.glide.Glide
import kotlinx.android.extensions.LayoutContainer
import org.jetbrains.anko.*

/**
 * Created by root on 1/16/18.
 */
class RecyclerViewAdapter(private val items: List<Item>, private val listener: (Item) -> Unit)
    : RecyclerView.Adapter<RecyclerViewAdapter.ViewHolder>() {

//    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int) =
//            RecyclerView.ViewHolder(LayoutInflater.from(context).inflate(item_list, parent, false))

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        return ViewHolder(ItemListUI().createView(AnkoContext.create(parent.context, parent)))
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        holder.bindItem(items[position], listener)
    }

    override fun getItemCount(): Int = items.size

    class  ItemListUI: AnkoComponent<ViewGroup> {
        override fun createView(ui: AnkoContext<ViewGroup>): View {
            return with(ui){
                linearLayout {
                    padding = dip(16)
                    orientation = LinearLayout.HORIZONTAL
                    imageView {
                        id = R.id.image
                        imageResource = R.drawable.img_barca
                    }.lparams(width = dip(50), height = dip(50))
                    textView {
                        id = R.id.name
                        //tools:text = Barcelona FC //not support attribute
                    }.lparams {
                        margin = dip(10)
                        gravity = Gravity.CENTER_VERTICAL
                    }
                }
            }
        }
    }

    class ViewHolder(override val containerView: View) : RecyclerView.ViewHolder(containerView),
            LayoutContainer {

        fun bindItem(items: Item,listener: (Item) -> Unit) {
            val name: TextView = itemView.find(R.id.name)
            val image: ImageView = itemView.find(R.id.image)
            name.text = items.name
            Glide.with(containerView).load(items.image).into(image)
            containerView.setOnClickListener { listener(items) }
        }
    }

}