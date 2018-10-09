class HelloWorldSwift: UIViewController {}

print("Hello, World!")


    let helloWorldLabel: UILabel = {
        let label = UILabel()
        label.text = "Hello World!!!"
        label.isUserInteractionEnabled = false
        label.translatesAutoresizingMaskIntoConstraints = false
        return label
    }()

      override func viewDidLoad() {
        super.viewDidLoad()

        view.addSubview(helloLabel)
      }

}