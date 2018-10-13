package com.chillguy.footballsubmission1final

import android.os.Parcelable
import kotlinx.android.parcel.Parcelize

/**
 * Created by root on 1/16/18.
 */
@Parcelize
data class Item (val name: String?, val image: Int?,val desc: String?) :Parcelable