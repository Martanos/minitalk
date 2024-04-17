#!/bin/bash

# Function to send a message to the server and measure the response time
send_message() {
    message="$1"
    start_time=$(date +%s.%N)

    # Run the client with Valgrind
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind.log ./client $server_pid "$message" 2>&1 >/dev/null

    end_time=$(date +%s.%N)
    response_time=$(echo "$end_time - $start_time" | bc)

    echo "Message: $message"
    echo "Response time: $response_time seconds"

    # Print the leak summary from Valgrind's output
    echo "Memory Leak Summary:"
    grep -E '(definitely|indirectly|possibly) lost:' valgrind.log

    echo "------------------------"
}

# Prompt the user to enter the server PID
read -p "Enter the server PID: " server_pid

echo "Mandatory Tests:"
echo "------------------------"

# Test case 1: ASCII characters
echo "Test case 1: ASCII characters:"
echo "------------------------"
ascii_chars=$(printf "%b" "$(printf '\\%03o' {32..126})")
send_message "$ascii_chars"

# Test case 2: Performance benchmark
echo "Test case 2: Performance benchmark:"
echo "------------------------"
echo "100 chars:"
send_message "$(perl -e 'print "A" x 100')"
echo "1000 chars:"
send_message "$(perl -e 'print "A" x 1000')"
echo "10000 chars:"
send_message "$(perl -e 'print "A" x 10000')"

# Test case 3: Multiple clients (sequential)
echo "Test case 3: Multiple clients (sequential):"
for i in {1..5}; do
    send_message "Message from client $i"
done

echo "Bonus Tests:"
echo "------------------------"

# Test case 4: Unicode support
echo "Test case 4: Unicode support:"
send_message "Тест на кириллице"
send_message "测试中文字符"
send_message "😀😃😄😁😆😅😂🤣"

echo "Additional Test:"
echo "------------------------"

# Test case 5: Bee Movie script and Unicode art
echo "Test case 5: Bee Movie script and Unicode art"
send_message "According to all known🧠 laws👨‍⚖️👩‍⚖️ of aviation🧐, there is no😧🤕 way a bee🐝🅱️ should be able to fly🛫."
send_message "Its wings are too small🍆😮 to get its fat🍑 little body😏 off the ground🌱."
send_message "The bee🐝🅱️, of course😒, flies🛫 anyway because bees🐝🅱️don't care😎 what humans🚶‍♂️ think is impossible😉."
send_message "Yellow💛, black🖤😁."
send_message "Yellow💛, black🖤🤨."
send_message "Yellow💛, black🖤😠."
send_message "Yellow💛, black🖤😡🤬🖕."
send_message "Ooh😸🥴😏, black🖤👀 and yellow💛🤩!"
send_message "Let's shake🧂 it up a little😏👌."
send_message "Barry!"
send_message "Breakfast🥞 is ready😃!"
send_message "Coming😈💦!"
send_message "Hang🧗‍♂️ on a second⌚️👀."
send_message "Hello😃?"
send_message "- Barry🤠?"
send_message "- Adam🤠?"
send_message "- Can you believe this is happening😱?"
send_message "- I can't😸."
send_message "I'll pick you up😁🚘."
send_message "Looking sharp😏👌."
send_message "Use the stairs😑."
send_message "Your father🧔 paid good money💸💰 for those🤨."
send_message "Sorry🥺."
send_message "I'm excited😁."
send_message "Here's the graduate👨‍🎓 ."
send_message "We're very proud of you, son😍☺️."
send_message "A perfect report card📝, all B's🅱️🏫👌😺."
send_message "Very proud☺️😚."
send_message "Ma!"
send_message "I got a thing going here😕."
send_message "- You got lint on your fuzz🤨."
send_message "- Ow!"
send_message "That's me😣!"
send_message "- Wave to us😃!"
send_message "We'll be in👉👌 row 118,000😁."
send_message "- Bye👋🙂!"
send_message "Barry, I told you, stop flying in the house😠!"
send_message "- Hey, Adam🤠."
send_message "- Hey, Barry🤠."
send_message "- Is that fuzz gel🤔?"
send_message "- A little👌."
send_message "Special day, graduation🥳👨‍🎓🎉."
send_message "Never thought I'd make it😸."
send_message "Three days grade school👦🧒🏫, three days high school😈🏫."
send_message "Those were awkward😳."
send_message "Three days college😴🏫."
send_message "I'm glad I took a day📅 and hitchhiked🏃‍♂️around the hive😉."
send_message "You did come back different🤔."
send_message "- Hi, Barry🤠."
send_message "- Artie, growing a mustache🧐?"
send_message "Looks good😄."
send_message "- Hear about Frankie🤨?"
send_message "- Yeah😀."
send_message "- You going to the funeral😔?"
send_message "- No, I'm not going😂🤣."
send_message "Everybody knows🧠, sting someone, you die💀😒."
send_message "Don't waste it on a squirrel🙄🐿."
send_message "Such a hothead😑."
send_message "I guess he could have just gotten out of the way🥵."
send_message "I love this incorporating an amusement park🎆 into our day😍😙."
send_message "That's why we don't need vacations🏖🤓."
send_message "Boy, quite a bit of pomp😼... under the circumstances😜😂🤣."
send_message "- Well, Adam, today we are men💪😏🍆."
send_message "- We are😄!"
send_message "- Bee-men☺️🐝."
send_message "- Amen🙏😊!"
send_message "Hallelujah⛪️🙏😁🤪!"
send_message "Students👨‍🎓, faculty, distinguished bees🐝🅱️👀, please welcome Dean Buzzwell."
send_message "Welcome, New Hive City🌃 graduating class of..."
send_message "...9:15⌚️👀."
send_message "That concludes our ceremonies🤗."
send_message "And begins your career at Honex Industries🍯🥳🎉!"
send_message "Will we pick our job🧰😴 today🤔?"
send_message "I heard it's just orientation😐."
send_message "Heads up🙂!"
send_message "Here we go😃."
send_message "Keep your hands✋ and antennas📞 inside🤣🤪 the tram👄💋😏🥴😩 at all times😜."
send_message "- Wonder what it'll be like🧐?"
send_message "- A little scary👻😖."
send_message "Welcome to Honex🍯, a division of Honesco and a part of the Hexagon Group😎😜🤣."
send_message "This is it😃!"
send_message "Wow🙂."
send_message "Wow🙃."
send_message "We know that you, as a bee🐝🅱️, have worked your whole life☠️😱 to get to the point where you can work for your whole life☠️👻💀."
send_message "Honey🍯 begins when our valiant Pollen Jocks👀👅🍆😏😎🥴 bring the nectar to the hive."
send_message "Our top-secret formula🔒🚫🧐 is automatically color-corrected🌈, scent-adjusted👃and bubble-contoured⭕️💋😏🥴into this soothing sweet syrup👁👄👁🤤 with its distinctive golden glow💛😋🅱️ you know🧠 as..."
send_message "Honey🍯😃🤩😜!"
send_message "- That girl🧑 was hot🔥🥴😏😈🍑💦."
send_message "- She's my cousin😨!"
send_message "- She is😱?"
send_message "- Yes, we're all cousins😤."
send_message "- Right✅."
send_message "You're right✅."
send_message "- At Honex🍯, we constantly strive to improve every aspect of bee existence☠️👌🐝."
send_message "These bees are stress-testing a new helmet⛑ technology👨‍💻👩‍💻😀."
send_message "- What do you think he makes💵🤔?"
send_message "- Not enough🤕😔."
send_message "Here we have our latest advancement⌚️🏆, the Krelman😁."
send_message "- What does that do🧐?"
send_message "- Catches that little strand of honey🍯 that hangs after you pour it🙂."
send_message "Saves us millions😁."
send_message "Can anyone work on the Krelman🙋‍♂️🤔?"
send_message "Of course🤗."
send_message "Most bee jobs🧰😴 are small👌🍆 ones."
send_message "But bees know that every small👌🍆 job🧰😴, if it's done well, means a lot😃."
send_message "But choose carefully🧐 because you'll stay in👉👌 the job🧰😴 you pick for the rest of your life🤪🥳💀."
send_message "The same job🧰😴 the rest of your life😰?"
send_message "I didn't know🧠 that😓."
send_message "What's the difference🤪?"
send_message "You'll be happy to know🧠 that bees🐝, as a species, haven't had one day off in 27 million years⌚️."
send_message "So you'll just work us to death☠️?"
send_message "We'll sure try😉."
send_message "Wow🤪!"
send_message "That blew my mind🤯!"
send_message "What's the difference?"
send_message "How can you say that😤?"
send_message "One job🧰😴 forever🤨?"
send_message "That's an insane choice to have to make😔."
send_message "I'm relieved🙂."
send_message "Now we only have to make one decision in👉👌 life😜."
send_message "But, Adam😕, how could they never have told us that😠?"
send_message "Why would you question anything?"
send_message "We're bees🐝🅱️."
send_message "We're the most perfectly functioning society on Earth🌎."
send_message "You ever think maybe things work a little too well here🤔?"
send_message "Like what🤨?"
send_message "Give me one example😤."
send_message "I don't know😯."
send_message "But you know what I'm talking about😤."
send_message "Please clear the gate."
send_message "Royal Nectar Force⚔️🛡 on approach."
send_message "Wait a second⌚️."
send_message "Check it out😯."
send_message "- Hey, those are Pollen Jocks👀🥴!"
send_message "- Wow."
send_message "I've never seen them this close😜."
send_message "They know what it's like outside the hive☺️."
send_message "Yeah, but some don't come back😥."
send_message "- Hey, Jocks🧑😏😝🍑🥳😩🤤🥴🔞!"
send_message "- Hi, Jocks🧑😏😝🍑🥳😩🤤🥴🔞!"
send_message "You guys did great👨‍🦳😃!"
send_message "You're monsters😈!"
send_message "You're sky freaks🏞!"
send_message "I love it😜!"
send_message "I love it😁!"
send_message "- I wonder where they were🤔🧐🤓."
send_message "- I don't know😯."
send_message "Their day's📅 not🤕🚫 planned."
send_message "Outside the hive, flying who knows where, doing who knows what🤔."
send_message "You can't just decide to be a Pollen Jock💪😻🍆."
send_message "You have to be bred for that😎."
send_message "Right✅."
send_message "Look👀."
send_message "That's more pollen than you and I will see in👉👌 a lifetime☠️👻."
send_message "It's just a status symbol😒."
send_message "Bees🐝🅱️ make too much of it."
send_message "Perhaps🤪."
send_message "Unless you're wearing it😎 and the ladies🧑 see you wearing it👀👄💋🍑😏🥴👉👌Those ladies?"
send_message "Aren't they our cousins too🙁?"
send_message "Distant🙂."
send_message "Distant🙃."
send_message "Look at these two😎."
send_message "- Couple of Hive Harrys🤓😂."
send_message "- Let's have fun with them😈."
send_message "It must be dangerous🚫 being a Pollen Jock💪🍆."
send_message "Yeah😎."
send_message "Once a bear🐻👅 pinned me🔞🥴😏😘😜 against a mushroom🍄!"
send_message "He had a paw on my throat😩😜😍, and with the other, he was slapping me👌🍆😩🥰😚🤪!"
send_message "- Oh, my!"
send_message "- I never thought I'd knock him out😩👉👌🍆🍑🐓😚😎."
send_message "What were you doing during this🧐?"
send_message "Trying to alert the authorities😏😩🥴🔥🍑."
send_message "I can autograph📝 that🥴😩😏."
send_message "A little gusty🌬 out there today, wasn't it, comrades😎?"
send_message "Yeah."
send_message "Gusty🌬."
send_message "We're hitting a sunflower🌻 patch six miles from here tomorrow😎."
send_message "- Six miles, huh😯?"
send_message "- Barry🤨!"
send_message "A puddle💧 jump🤾‍♂️ for us, but maybe you're not up for it😎."
send_message "- Maybe I am😏."
send_message "- You are not😠!"
send_message "We're going 0900 at J-Gate👿."
send_message "What do you think, buzzy-boy🐝?"
send_message "Are you bee enough🍆😈🥴🐓👀👅😏😎👉👌?"
send_message "I might be😏🥴."
send_message "It all depends on what 0900 means😏😩🍆🥴👉👌."
send_message "Hey, Honex🤠!"
send_message "Dad😱, you surprised me😨."
send_message "You decide what you're interested in🤠?"
send_message "- Well, there's a lot of choices😓."
send_message "- But you only get one😰."
send_message "Do you ever get bored😴 doing the same job🧰😴 every day📅🤔?"
send_message "Son, let me tell you about stirring😃."
send_message "You grab that stick, and you just move it around, and you stir it around😄."
send_message "You get yourself into a rhythm🎵🎶."
send_message "It's a beautiful thing😻."
send_message "You know, Dad, the more I think about it, maybe the honey🍯 field just isn't right for me😔."
send_message "You were thinking of what, making balloon animals😒?"
send_message "That's a bad job🧰😴 for a guy with a stinger😜."
send_message "Janet👩‍🦱, your son's not sure he wants to go into honey🍯!"
send_message "- Barry, you are so funny😂 sometimes😂😂😂."
send_message "- I'm not trying to be funny😠."
send_message "You're not funny☹️!"
send_message "You're going into honey👄🍯."
send_message "Our son, the stirrer😆!"
send_message "- You're gonna be a stirrer😃?"
send_message "- No one's listening to me😠!"
send_message "Wait till you see the sticks I have😏"
send_message "🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝"
send_message "🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝"
send_message "🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝"
send_message "🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝"
send_message "🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝"
send_message "🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝"
send_message "🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝🐝"