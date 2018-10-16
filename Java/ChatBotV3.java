package chat;

import java.util.Scanner;
import lib.StringArray;
import java.util.Calendar;
import java.text.SimpleDateFormat;
import java.text.DateFormat;


public class ChatBotV3 {

public static String[] userResponses = new String[1000];//initialize new 1000 space user response string array
public static int resCount = 0; //will go from 0-999
public static String userResponse;

  /**
  carry on a conversation with the user acting as their supposed mother
  @param args an array of Strings which we ignore
  */
  public static void main(String[] args){

    Scanner scanner = new Scanner(System.in);

    System.out.println("Hello, this is your mother speaking.");
    boolean done=false;

    while (!done){
      userResponse = scanner.nextLine();
      userResponses[resCount] = userResponse;//stores user responses into the array
      String[] words = userResponse.split("\\s+");
      String momResponse = generateResponse(words);
      System.out.printf("%s%n%n",momResponse);
      done = userResponse.equals("bye");
      resCount = resCount + 1;
    }
  }

  /**
    generates a String in response to a user response
    passed in as an array of words
    @param words the user's response
    @return a string responding to the user's words
  */
  public static String generateResponse(String[] words){

    if (words.length <=3) {
      // respond to a short response
      return StringArray.pickRandom(shortBanter);

    } else if (userResponse.equalsIgnoreCase("Who is your author?")) {
      return "My author is Alexander.";

    } else if (userResponse.equalsIgnoreCase("What are these responses based on?")) {
      return "These responses are based on actual discussions between the author and his mother.";

    } else if (userResponse.equalsIgnoreCase("What time is it?")) {
      return getDateTime();

    } else if (words.length >= 30) {
      // respond to a long response
      return StringArray.pickRandom(longResponse);
    } else if (StringArray.intersects(words,foodWords)){
      // respond to a user response mentioning food
      return StringArray.pickRandom(foodResponses);
    } else if (Math.random() < 0.8) {
      // 80% of the time pick a random generic response
      return StringArray.pickRandom(momResponses);
    } else {
      // the rest of the time bring up something from earlier
      return reState((int)(Math.random()*resCount));
    }

  }


  public static String getDateTime() {
    DateFormat dateformat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
    Calendar cal = Calendar.getInstance();
    return dateformat.format(cal.getTime());
  }


  /**
    a method of of generic responses to a user comment
  */
  public static String reState(int randomIndex){
    return "Earlier you said '"+userResponses[randomIndex]+"' , please elaborate on this";
  }

   /**
     an array of responses to a short user comment
   */
   public static String[] shortBanter =
   {
     "I'm doing fine thanks.",
     "I'm at home.",
     "What else?",
     "Hello to you too.",
     "Why are you being so taciturn?",
     "You are going to need to say more than that if you want an actual response",
     "Hello? Speak up I cant hear you over the sound of the landscapers mowing the lawn",
     "When will you be home?",
     "Ok, Goodnight.",
     "Yes."
   };
   /**
    an array of responses to a long user comment
    */
   public static String[] longResponse =
   {
     "I'm sorry, were you talking?",
     "I was falling asleep by the sheer length of your story.",
     "*Yawn*",
     "Please, shorten your message.",
     "I literally can't respond because that was just too much in one message.",
     "Please, didn't you learn how to not write run-on sentences in school?",
     "You mind if you shorten your message a little?",
     "That message was much too hard to comprehend.",
     "There was simply too much to take into account with your last message.",
     "Hey Sweetie, Mommy can't respond properly if you message is simply too lengthy."
   };

   /**
     an array of general inquiries used to change the subject
   */
   public static String[] momResponses =
      {
        "So, how is school?",
        "How has your love life been going lately? Hmmmm?????",
        "Are you spending enough time outside with your friends?",
        "How have your grades been coming along this semester?",
        "When is the next time you are coming home?",
        "Do you need me to buy anything for you for college?",
        "Anything of note occur recently?",
        "When was the last time you washed your clothes and cleaned your sheets?",
        "Are you sleeping alright?",
        "Remember to always try to make new friends. Are you doing alright in that sphere?",
        "What are you doing with your weekends?",
        "You should put on a jacket its getting cold outside.",
      };

  /**
    an array of words related to food, that lead to a "foodReponses"
  */
  public static String[] foodWords = {"breakfast","lunch","dinner","brunch",
    "supper","food","eat","eating","snack"};

  /**
    an array of responses to sentences that contain a food reference
  */
  public static String[] foodResponses =
     {
       "Are you hungry?",
       "What do you want for food tonight?",
       "What did you eat for lunch today? It better have been healthy.",
       "What do you want for breakfast tomorrow?",
       "Have you been eating all right for college?",
       "Dinner will be spaghetti and meatballs despite your pleas to the contrary.",
       "Do you want to go out to eat tonight?",
       "Make yourself something to eat, I'm lazy.",
       "I'll make you a snack for when I come to pick you up.",
       "I'll make your favorite tonight for dinner."
    };







}
