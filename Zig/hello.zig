const std = @import("std");

pub fn main() !void {
    var stdout = try std.io.getStdOut();
    try stdout.write("Hello, world!\n");
}
