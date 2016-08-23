# text-game-base
This is a basic library for text-based, choice-based adventure games. It is still in early stages, but below are
some short descriptions of the classes we have so far.


##Exposition
  This class represents any amount of story that is to be displayed to the reader without their interaction. Hence,
  Exposition. On creation it takes a vector of character pointers (not a std::string, because the split function works on
  vectors of char pointers) that it will then split into paragraphs (the delimiter is '\n' by default, and is currently
  hard-coded, though that will hopefully change eventually) which it will store in another vector. When you call the
  function Exposition::exposit() it will display each paragraph one at a time, waiting for player input before moving on
  to the next one, allowing the player to read at their own speed without being bombarded by enormous amounts of text.
  
##Decision
  With Exposition and Reaction, this is really the foundation of this game. A Decision represents a choice that must
  be made by the player. On creation it takes a std::string that is the paragraph introducing the choice (in Mass
  Effect or The Walking Dead games this would be equivocal to the text that hovers above the decision you are about
  to make so that you can remember what you are reacting to), and it also takes a vector of char pointers which it
  handles in the same way as with Exposition, except that instead of separating them into paragraphs, it treats each
  segment as the word-description of one of the choices (see the example below for clarification).
  
  Calling Decision::present() will display the introduction to the decision, and then display each choice next to
  a number that it corresponds to for player input. Once that is done, you may call Decision::decide to take the
  user's input, make sure it is a number. If it is a number that corresponds to one of the choices then return it,
  otherwise, ask for valid input.
  
  Ex:
    
    string intro = "Tell me, good sir/madam, what is thy profession?";
    char choices[] = "Yarrr, I be a pirate!\nI am a mighty knight!\nOh, I am just a humble servant, sir.\nThat, good sir/madam, is none of your business!";

    Decision d(intro, choices);
    d.present();
    int choice = d.decide();
    
    This outputs:
      Tell me, good sir/madam, what is thy profession?
      0: Yarrr, I be a pirate!
      1: I am a mighty knight!
      2: Oh, I am just a humble servant, sir.
      3: That, good sir/madam, is none of your business!
      
      What is your choice? 
      
    And then takes their input and returns it.
    
    
##Reaction
  This will be coming soon. This reacts to a decision that was made.
    
