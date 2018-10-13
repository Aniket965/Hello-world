package com.chillguy.footballmatchschedule

import kotlinx.coroutines.experimental.android.UI
import kotlin.coroutines.experimental.CoroutineContext


open class CoroutineContextProviderAll {
    open val main: CoroutineContext by lazy { UI }
}
/**Kelas dan context di atas harus diberi modifier open agar nantinya kita bisa mewariskannya.
// by lazy pada context di atas digunakan untuk menginisialisasi value hanya pada saat pertama kali digunakan.
// Sekarang saya bisa menggunakannya sebagai constructor pada presenter dan mengubah async(UI) menjadi async(context.main).
// Pastinya di MatchPresenter dan DetailPresenter*/