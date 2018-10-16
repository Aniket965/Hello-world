import UIKit
import PlaygroundSupport

class ViewController : UIViewController {
    
    override func loadView() {
        let view = UIView()
        view.backgroundColor = .white

        let label = UILabel()
        label.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(label)
        self.view = view
        
        label.centerXAnchor.constraint(equalTo: view.centerXAnchor).isActive = true
        label.centerYAnchor.constraint(equalTo: view.centerYAnchor).isActive = true
        
        label.text = "Hello World!"
        label.textColor = .black

    }
}

PlaygroundPage.current.liveView = ViewController()
