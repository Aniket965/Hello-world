package com.examples.android

class SingletonExample {

    init {
    }

    companion object {
        private var mInstance: SingletonExample? = SingletonExample()
        @Synchronized
        fun getInstance(): SingletonExample {
            if (mInstance == null) {
                mInstance = SingletonExample()
            }
            return mInstance!!
        }
    }

    fun destroy() {
        mInstance = null
    }
}