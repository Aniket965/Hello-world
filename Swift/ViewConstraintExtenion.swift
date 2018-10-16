// Created by Nikhil Sharma on 16/10/18.
// These constraint variable will return instance of constraint without need of creating a constraint outlet. 

import Foundation
import UIKit

extension UIView{
    
    var topConstarint:NSLayoutConstraint? {return self.superview?.constraints.filter{$0.firstAttribute == .top}.first}
    
    var bottomConstarint:NSLayoutConstraint? {return self.superview?.constraints.filter{$0.firstAttribute == .bottom}.first}
    
    var leadingConstarint:NSLayoutConstraint? {return self.superview?.constraints.filter{$0.firstAttribute == .leading}.first}
    
    var trailingConstarint:NSLayoutConstraint? {return self.superview?.constraints.filter{$0.firstAttribute == .trailing}.first}
    
    var heightConstarint:NSLayoutConstraint? {return self.constraints.filter{$0.firstAttribute == .height}.first}
    
    var widthConstarint:NSLayoutConstraint? {return self.constraints.filter{$0.firstAttribute == .width}.first}
    
}
