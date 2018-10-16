# Steps to run (must have Docker installed!)
# Build the image using:
# $ docker build -f hello-world.dockerfile -t hello-world .
# Run the image using:
# $ docker run --rm hello-world
# --rm deletes  the container once the program runs
# so that it doesn't take up precious disk space!
# -f specifies this dockerfile and -t gives the image
# a name


# Pulls the latest bash image from Docker Hub
FROM bash:latest

LABEL author="Alberto Franco @afranco07"

# Runs the command `$ echo Hello, world!`
CMD [ "echo", "Hello, world!" ]

# To delete image:
# docker rmi hello-world

