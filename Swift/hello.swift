class HelloWorldSwift: UIViewController {}

print("Hello, World!")


    let helloWorldLabel: UILabel = {
        let label = UILabel()
        label.text = "Hello World!!! hackoctober is here.."
        label.isUserInteractionEnabled = false
        label.translatesAutoresizingMaskIntoConstraints = false
        return label
    }()

    var array = []

      override func viewDidLoad() {
        super.viewDidLoad()

        setupViews()

        view.addSubview(helloworldLabel)
      }


      func setupViews() {

        view.addSubview(helloWorldLabel)

        helloWorldLabel.centerXAnchor.constraint(equalTo: view.centerXAnchor).isActive = true
        helloWorldLabel.centerYAnchor.constraint(equalTo: view.centerYAnchor).isActive = true
      }

}
