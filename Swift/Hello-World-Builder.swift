
import Foundation

enum GreetingsCategory: Int{
    case formalHello, casualHello, swagHello
}

struct Greeting{
    var hello_str: String
}

struct GreetingSentence{
    var greeting: Greeting
    var time: String
    var address: String
}

struct GreetingParagraph{
    var formalGreetings: [GreetingSentence] = []
    var casualGreetings: [GreetingSentence] = []
    var swagGreetings: [GreetingSentence] = []
    
    var num_sentences: Int {
        let sentences = formalGreetings+casualGreetings+swagGreetings
        return sentences.count
    }
}


// Builder
class HelloBuilder {
    private var greetingParagraph: GreetingParagraph?
    
    init(){
        self.greetingParagraph = GreetingParagraph()
    }
    
    func setFormalHello(_ hello: Greeting, time: String, address: String){
        let sentence = GreetingSentence(greeting: hello, time: time, address: address)
        set(sentence, at: greetingParagraph?.formalGreetings, withCategory: .formalHello)
    }
    
    func setCasualHello(_ hello: Greeting, time: String, address: String){
        
        let sentence = GreetingSentence(greeting: hello, time: time, address: address)
        set(sentence, at: greetingParagraph?.casualGreetings, withCategory: .casualHello)
    }
    
    func setSwagHello(_ hello:Greeting, time: String, address: String){
        
        let sentence = GreetingSentence(greeting: hello, time: time, address: address)
        set(sentence, at: greetingParagraph?.swagGreetings, withCategory: .swagHello)
    }
    
    func getResult()->GreetingParagraph{
        return greetingParagraph!
    }
    
    private func set(_ sentence: GreetingSentence, at helloArrays: [GreetingSentence]?, withCategory greetingCategory: GreetingsCategory){
        
        guard let hellos = helloArrays else{ return}
        
        var greetsentence: GreetingSentence? = hellos.filter ({
            $0.greeting.hello_str == sentence.greeting.hello_str
            }).first
        
        guard greetsentence == nil else{return}
        
        switch greetingCategory{
        case .formalHello:
            greetingParagraph?.formalGreetings.append(greetsentence!)
        case .casualHello:
            greetingParagraph?.casualGreetings.append(greetsentence!)
        case .swagHello:
            greetingParagraph?.swagGreetings.append(greetsentence!)
        }
    }
}

