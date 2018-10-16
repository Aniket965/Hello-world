rm(list = ls())

library(ggplot2)
library(datasets)

#load cars dataset
data(mtcars)

p <- ggplot(mtcars, aes(wt, mpg, label = "Hello World")) + 
      geom_text(aes(color = cyl), size = 2) +
      xlab("Hello World") +
      ylab("Hellow World") +
      theme_minimal()
ggsave(p, file="helloworld_ggplot.png")
