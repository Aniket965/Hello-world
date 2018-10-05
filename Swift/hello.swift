import UIKit
import Foundation
let message: String = "Hello, World!"
print(message, terminator: "") 
fileManager.createFile(path:"/", contents: message, attributes:[FileAttributeKey : Any]? = nil)
