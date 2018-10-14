fun main(args: Array<String>) {

    var walmart = ShoppingList("Walmart")

    walmart.addGroceryItem(GroceryItem("Milk", 2))
    walmart.addGroceryItem(GroceryItem("Milk", 6))

    println(walmart.getGroceryItems().size)
}

class GroceryItem(var name: String, var quantity: Int) {
}

class ShoppingList(var name: String) {

    private var groceryItems = mutableListOf<GroceryItem>()

    fun addGroceryItem(groceryItem: GroceryItem) {

        val gi = this.groceryItems.find {
            it.name == groceryItem.name
        }

        if (gi == null) {
            this.groceryItems.add(groceryItem)
        }
    }

    fun getGroceryItems(): MutableList<GroceryItem> {
        return this.groceryItems
    }
}