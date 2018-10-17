$(Document).ready(generateQuote);

var quoteIndex = -1;

$("#new").on("click", generateQuote);

function pickQuote() {
  quoteIndex = Math.floor(Math.random() * quotes.length);
  return quotes[quoteIndex];
}

function generateQuote() {
  var quote = pickQuote();
  $("#quote").html("\"" + quote.quote + "\"");
  $("#author").html(" - " + quote.author);
  $("#tweet").attr("href", "https://twitter.com/intent/tweet?text=%22" + quote.quote + "%22%0D%0A- " + quote.author);
}

var quotes = [{
  quote: "It is the mark of an educated mind to be able to entertain a thought without accepting it.",
  author: "Aristotle"
}, {
  quote: "It is not so much that I have confidence in scientists being right, but that I have so much in nonscientists being wrong.",
  author: "Isaac Asimov"
}, {
  quote: "Nature, to be commanded, must be obeyed.",
  author: "Francis Bacon"
}, {
  quote: "Prosperity is not without many fears and distastes, and adversity is not without comforts and hopes.",
  author: "Francis Bacon"
}, {
  quote: "Some books are to be tasted, others to be swallowed, and some few to be chewed and digested: that is, some books are to be read only in parts, others to be read, but not curiously, and some few to be read wholly, and with diligence and attention.",
  author: "Francis Bacon"
}, {
  quote: "In theory, theory and practice are the same. In practice, they are not.",
  author: "Yogi Berra"
}, {
  quote: "You can tell a lot just by looking at it.",
  author: "Yogi Berra"
}, {
  quote: "An expert is a man who has made all the mistakes that can be made in a very narrow field.",
  author: "Niels Bohr"
}, {
  quote: "Never express yourself more clearly than you are able to think.",
  author: "Niels Bohr"
}, {
  quote: "Prediction is very difficult, especially about the future.",
  author: "Niels Bohr"
}, {
  quote: "War es ein Gott der diese Zeichen schreib? (translation: Was it a god who wrote these signs?)",
  author: "Ludwig Boltzmann, quoting Gothe, about Maxwell's equations"
}, {
  quote: "Never interrupt an enemy when he is making a mistake.",
  author: "Napoleon Bonaparte"
}, {
  quote: "If God has made the world a perfect mechanism, He has at least conceded so much to our imperfect intellects that in order to predict little parts of it, we need not solve innumberable differential equations, but can use dice with fair success.",
  author: "Max Born"
}, {
  quote: "It is important that students bring a certain ragamuffin, barefoot, irreverence to their studies; they are not here to worship what is known, but to question it.",
  author: "Jacob Bronowski, The Ascent of Man (1973)"
}, {
  quote: "I know that this defies the law of gravity, but, you see, I never studied law.",
  author: "Bugs Bunny"
}, {
  quote: "Alice: How long is forever? White Rabbit: Sometimes, just one second.",
  author: "Lewis Carrol"
}, {
  quote: "The wise are instructed by reason, average minds by experience, the stupid by necessity, and the brute by instinct.",
  author: "Marcus Cicero"
}, {
  quote: "If no use is made of the labor of past ages, the world must remain always in the infancy of knowledge.",
  author: "Marcus Cicero"
}, {
  quote: "By doubting we arrive at the truth.",
  author: "Marcus Cicero"
}, {
  quote: "Only feeble minds are paralyzed by facts.",
  author: "Arthur Clarke"
}, {
  quote: "I hear and I forget. I see and I remember. I do and I understand.",
  author: "Confucius"
}, {
  quote: "We find comfort among those who agree with us -- growth among those who don't.",
  author: "Frank A. Clark"
}, {
  quote: "There are three kinds of lies: lies, damned lies, and statistics.",
  author: "Benjamin Disraeli"
}, {
  quote: "There is nothing more deceptive than an obvious fact.",
  author: "Arthur Conan Doyle"
}, {
  quote: "Never accept a fact until it has been verified by theory.",
  author: "Arthur Eddington"
}, {
  quote: "The secret to creativity is knowing how to hide your sources.",
  author: "Albert Einstein"
}, {
  quote: "The only thing that interferes with my learning is my education.",
  author: "Albert Einstein"
}, {
  quote: "Equations are more important to me, because politics is for the present, but an equation is something for eternity.",
  author: "Albert Einstein"
}, {
  quote: "Do not go where the path may lead. Go instead where there is no path and leave a trail.",
  author: "Ralph Waldo Emerson"
}, {
  quote: "I suggest that you change the wording of your statement from 'important' to 'interesting'. Your work can always be interesting to you, even if it is not interesting to the rest of us. As for whether it is important, well, that requires a far higher standard.",
  author: "Michael E. Fisher"
}, {
  quote: "Either write something worth reading or do something worth writing.",
  author: "Benjamin Franklin"
}, {
  quote: "I do not feel obliged to believe that the same God who has endowed us with sense, reason, and intellect has intended us to forego their use.",
  author: "Galileo Galilei"
}, {
  quote: "My goal is simple. It is complete understanding of the universe, why it is as it is and why it exists at all.",
  author: "Stephen Hawking"
}, {
  quote: "Adversity has the effect of eliciting talents, which in prosperous circumstances would have lain dormant.",
  author: "Horace"
}, {
  quote: "Facts do not cease to exist because they are ignored.",
  author: "Aldous Huxley"
}, {
  quote: "I don't care a damn for your loyalty when you think I am right; when I really want it most is when you think I am wrong.",
  author: "Lyndon Johnson"
}, {
  quote: "Nothing worthwhile is ever fun.",
  author: "Arthur Kornberg"
}, {
  quote: "Thou shalt not believe something just because you can explain it.",
  author: "Arthur Kornberg, Third from his 'Ten Commandments of Enzymology'"
}, {
  quote: "Life is like a piano. What you get out of life depends on how you play it.",
  author: "Tom Lehrer"
}, {
  quote: "Refrain from illusions, insist on work and not words, patiently seek divine and scientific truth.",
  author: "last words of Maria Mendeleeva to her son Dmitri (c.1850)"
}, {
  quote: "Arithmetic is being able to count up to twenty without taking off your shoes.",
  author: "Mickey Mouse"
}, {
  quote: "If I have seen further, it is by standing on the shoulders of giants.",
  author: "Sir Isaac Newton"
}, {
  quote: "Everyone you ever meet knows something you don't.",
  author: "Bill Nye"
}, {
  quote: "There's a time to soar like an eagle and a time to burrow like a worm. It takes a pretty sharp cookie to know when to shed the feathers and ... (long pause) ... to begin munching the humus!",
  author: "Lars Onsager"
}, {
  quote: "Chance favors the prepared mind.",
  author: "Louis Pasteur"
}, {
  quote: "Inspiration exists, but it has to find you working.",
  author: "Pablo Picasso"
}, {
  quote: "An important scientific innovation rarely makes its way by gradually winning over and converting its opponents... What does happen is that its opponents gradually die out and that the growing generation is familiarized with the idea from the beginning.",
  author: "Max Planck, The Philosophy of Physics (1936)"
}, {
  quote: "Insight must precede application.",
  author: "Max Planck"
}, {
  quote: "Experiments are the only means of knowledge at our disposal; the rest is poetry, imagination.",
  author: "Max Planck"
}, {
  quote: "The mind is not a vessel to be filled but a fire to be kindled.",
  author: "Plutarch"
}, {
  quote: "Contrary to the outstanding work of art, outstanding theory is susceptible to improvements.",
  author: "K. Popper"
}, {
  quote: "So many of our dreams at first seem impossible, then they seem improbable, and then, when we summon the will, they soon become inevitable.",
  author: "Christopher Reeve"
}, {
  quote: "Somewhere, something incredible is waiting to be known.",
  author: "Carl Sagan"
}, {
  quote: "Just the fact that some geniuses were laughed at does not imply that all who are laughed at are geniuses. They laughed at Columbus, they laughed at Fulton, they laughed at the Wright brothers. But they also laughed at Bozo the Clown.",
  author: "Carl Sagan"
}, {
  quote: "When I was your age, I didn't watch television! I LIVED! So... move out of your parent's basements!",
  author: "William Shatner on SNL, 1986"
}, {
  quote: "Anyone can initiate. The real skill is knowing how to 'finitiate'.",
  author: "Dave Thirumalai"
}, {
  quote: "It is disconcerting to reflect on the number of students we have flunked in chemistry for not knowing what we later found to be untrue.",
  author: "Robert L. Weber, Science With a Smile"
}, {
  quote: "Democracy is the recurrent suspicion that more than half of the people are right more than half of the time.",
  author: "E. B. White"
}, {
  quote: "If you don't have the time to do it right, when will you have the time to do it over?",
  author: "John Wooden"
}, {
  quote: "Never mistake activity for achievement.",
  author: "John Wooden"
}, {
  quote: "Times have changed. In the Bible, when an ass spoke, it was considered a miracle.",
  author: "anonymous"
}, {
  quote: "If you don't ask, the answer will always be no.",
  author: "anonymous"
}, {
  quote: "If I agreed with you, we'd both be wrong.",
  author: "anonymous"
}, {
  quote: "A clear conscience is usually the sign of a bad memory.",
  author: "anonymous"
}, {
  quote: "I didn't say it was your fault. I said I was blaming you.",
  author: "anonymous"
}, {
  quote: "Always take life with a grain of salt, ...plus a slice of lemon, ...and a shot of tequila.",
  author: "anonymous"
}, {
  quote: "If everything seems under control, you're just not going fast enough.",
  author: "Mario Andretti"
}, {
  quote: "You can’t use up creativity. The more you use, the more you have.",
  author: "Maya Angelou"
}, {
  quote: "You are the average of the five people you associate with most",
  author: "Tim Ferriss"
}, {
  quote: "Most people are fast to stop you before you get started but hesitate to get in the way if you’re moving.",
  author: "Tim Ferriss"
}, {
  quote: "A person's success in life can usually be measured by the number of uncomfortable conversations he or she is willing to have.",
  author: "Tim Ferriss"
}, {
  quote: "A man is rich in proportion to the number of things he can afford to let alone.",
  author: "Henry David Thoreau"
}]