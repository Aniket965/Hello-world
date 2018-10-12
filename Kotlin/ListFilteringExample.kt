class SampleModel(var id: Int, var name: String) {}

class SampleClass {
    var sampleModels: MutableList<SampleModel> = mutableListOf(SampleModel(1, "test1"), SampleModel(3, "example1"), SampleModel(5, "test2"), SampleModel(8, "example2"))

    fun sampleMethod() {
        val filteredList = sampleModels.filter { model -> model.name.contains("example") && model.id > 4 }
    }
}