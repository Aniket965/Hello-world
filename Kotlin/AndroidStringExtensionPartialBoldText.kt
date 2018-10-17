import android.graphics.Typeface
import android.support.v7.app.ActionBar
import android.text.Spannable
import android.text.SpannableStringBuilder
import android.text.style.StyleSpan

/**
 * This function requires that the parts of the string that need
 * to be bolded are wrapped in * and * tags
 */
fun String.makePartialTextsBold(): SpannableStringBuilder {
    var copy = this
    return SpannableStringBuilder().apply {
        var setSpan = true
        var next: String
        do {
            setSpan = !setSpan
            next = if (length == 0) copy.substringBefore("*", "") else copy.substringBefore("*")
            val start = length
            append(next)
            if (setSpan) {
                setSpan(StyleSpan(Typeface.BOLD), start, length,
                        Spannable.SPAN_EXCLUSIVE_EXCLUSIVE)
            }
            copy = copy.removePrefix(next).removePrefix("*")
        } while (copy.isNotEmpty())
    }
}