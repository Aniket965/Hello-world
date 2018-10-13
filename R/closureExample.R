# Here we will see how the global assign operator works 

newBankAccount <- function(){
  myMoney <- 0
  putMonyInTheBank <- function(amount){
    # Note that the <<- is the global assign operator
    myMoney <<- myMoney + amount
  }
  howMuchDoIOwn <- function(){
    print(paste('You have:',myMoney,'bitcoins!'))
  }
  return(list2env(list(putMonyInTheBank=putMonyInTheBank,
                       howMuchDoIOwn=howMuchDoIOwn)))
}

# Example usage:

# > myAccount <- newBankAccount()
# > myAccount$howMuchDoIOwn()
# [1] "You have: 0 bitcoins!"
# > myAccount$putMonyInTheBank(200)
# > myAccount$howMuchDoIOwn()
# [1] "You have: 200 bitcoins!"
# > copyAccount <- myAccount
# > copyAccount$howMuchDoIOwn()
# [1] "You have: 200 bitcoins!"
# > copyAccount$putMonyInTheBank(300)
# > copyAccount$howMuchDoIOwn()
# [1] "You have: 500 bitcoins!"
# > myAccount$howMuchDoIOwn() # Ahh snap, I also received bitcoins!
# [1] "You have: 500 bitcoins!"
