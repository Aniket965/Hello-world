func systemUptime() -> TimeInterval {
    var currentTime = time_t()
    var bootTime    = timeval()
    var mib         = [CTL_KERN, KERN_BOOTTIME]

    var size = MemoryLayout<timeval>.stride
    let result = sysctl(&mib, u_int(mib.count), &bootTime, &size, nil, 0)
    if result != 0 {
        print("ERROR - \(#file):\(#function) - errno = "
            + "\(result)")
        return 0
    }

    time(&currentTime)
    let uptime = currentTime - bootTime.tv_sec
    
    return TimeInterval(uptime)
}