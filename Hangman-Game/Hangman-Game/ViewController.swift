//
//  ViewController.swift
//  Hangman-Game
//
//  Created by Sohardh Chobera on 22/06/18.
//  Copyright © 2018 Sohardh Chobera. All rights reserved.
//
//
//  create arrays to hold the words and hints (need wordtoGuess and wordAsUnderscores varibales) : DONE
//  need some way to randomise which word is selected, then select the word and the hint and display them
//  need a way to keep track of number of guesses being used
//  need a way to guess a letter and process whether it is or not in the wordToGuess
//  if correct, display updated wordAsUnderscores, if incorrect, decreement number of guesses, and letter to letter bank and display letters guessed
//  lose game if we run out of guesses
//  win game if we guess every letter before running out of guesses(if wordAsUnderscores contains no more underscores, then we win)


import UIKit

class ViewController: UIViewController,UITextFieldDelegate {
    
    @IBOutlet weak var hintLabel: UILabel!
    @IBOutlet weak var wordToGuessLabel: UILabel!
    @IBOutlet weak var remainingGuessesLabel: UILabel!
    @IBOutlet weak var inputTextField: UITextField!
    @IBOutlet weak var letterBankLabel: UILabel!
    
    let LIST_OF_WORDS : [String] = ["hello","goodbye","sohardh","hangman","coffee"]
    let LIST_OF_HINTS : [String] = ["greeting","farewell","chobera","letter guessing game","a good way to wake up"]
    
    var wordToGuess :String!
    var wordAsUnderscores : String! = ""
    let MAX_NUMBER_OF_GUESSES : Int = 5
    var guessesRemaning : Int!
    var oldRandomNumber :Int = 0
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    inputTextField.delegate = self
        //inputTextField.becomeFirstResponder()
    }
    
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
    @IBAction func chooseNewWordAction(_ sender: UIButton) {
        reset()
        let index = chooseRandomNumber()
        wordToGuess = LIST_OF_WORDS[index]
        let hint = LIST_OF_HINTS[index]
        hintLabel.text = "Hint : \(hint), \(wordToGuess.count) letters"
        
        //wordToGuessLabel.text = wordToGuess
        
        for _ in 1 ... wordToGuess.count {
           wordAsUnderscores.append("_")
        }
        print(wordAsUnderscores.count)
        wordToGuessLabel.text = wordAsUnderscores
        
        
    }
    
    func reset(){
        guessesRemaning = MAX_NUMBER_OF_GUESSES
        remainingGuessesLabel.text = " \(guessesRemaning!) guesses left"
        wordAsUnderscores = ""
    }
    
    func chooseRandomNumber() ->Int {
        var newRandomNumber : Int = Int(arc4random_uniform(UInt32(LIST_OF_WORDS.count)))
        print(newRandomNumber)
        if (newRandomNumber == oldRandomNumber){
            newRandomNumber = chooseRandomNumber()
        } else {
            oldRandomNumber = newRandomNumber
        }
        return newRandomNumber
    }
    
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        textField.resignFirstResponder()
        return true
    }
    
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        
        let allowedCharacters = NSCharacterSet.letters
        let startinglength = textField.text?.count ?? 0
        let lengthToAdd = string.count
        let lengthToReplace = range.length
        let newLength = startinglength + lengthToAdd - lengthToReplace
        
        if string.isEmpty {
            return true
        } else if(newLength == 1) {
            if let _ = string.rangeOfCharacter(from: allowedCharacters, options: .caseInsensitive){
                return true
            }
        }
        return false
    }
    
    func textFieldDidEndEditing(_ textField: UITextField) {
        guard let  letterGuessed = textField.text else {return}
        if wordToGuess.contains(letterGuessed){
            processCorrectGuess(letterGuessed : letterGuessed)
        } else {
            processIncorrectGuess()
        }
    }
    //hello
    func processCorrectGuess(letterGuessed : String){
        let characterGuessed = Character(letterGuessed)
        for index in wordToGuess.indices {
            if wordToGuess[index] == characterGuessed{
                let endIndex = wordToGuess.index(after: index)
                let charRange = index..<endIndex
                wordAsUnderscores = wordAsUnderscores.replacingCharacters(in: charRange, with: letterGuessed)
                wordToGuessLabel.text = wordAsUnderscores
            }
        }
        if !(wordAsUnderscores.contains("_")){
            remainingGuessesLabel.text = "You win :)"
            inputTextField.isEnabled = false
        }
    }
    func processIncorrectGuess(){
        
    }
    

}

