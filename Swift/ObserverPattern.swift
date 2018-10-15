//POST NOTIFICATION
NotificationCenter.default.post(name: Notification.Name("NotificationIdentifier"), object: nil)
// OR
NotificationCenter.default.post(name: Notification.Name("NotificationIdentifier"), object: nil, userInfo: ["Renish":"Dadhaniya"])

// RECEIVE NOTIFICATION
NotificationCenter.default.addObserver(self, selector: #selector(self.methodOfReceivedNotification(notification:)), name: Notification.Name("NotificationIdentifier"), object: nil)

// NOTIFICATION MANAGEMENT
@objc func methodOfReceivedNotification(notification: Notification){
  // TODO
}
