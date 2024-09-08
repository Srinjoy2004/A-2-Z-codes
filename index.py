# import speech_recognition as sr

# # Initialize the recognizer
# recognizer = sr.Recognizer()

# # Capture audio from the microphone
# with sr.Microphone() as source:
#     print("Please say something...")
#     audio = recognizer.listen(source)

#     try:
#         # Convert the speech to text
#         text = recognizer.recognize_google(audio)
#         print("You said: " + text)
#     except sr.UnknownValueError:
#         print("Sorry, I could not understand the audio.")
#     except sr.RequestError as e:
#         print(f"Could not request results from the recognition service; {e}")


import speech_recognition as sr

# Initialize the recognizer
recognizer = sr.Recognizer()

# Set up the microphone
with sr.Microphone() as source:
    print("Adjusting for ambient noise, please wait...")
    recognizer.adjust_for_ambient_noise(source, duration=1)
    print("Listening...")

    try:
        while True:
            # Capture audio from the microphone
            audio = recognizer.listen(source, phrase_time_limit=2)

            # Convert the speech to text
            try:
                text = recognizer.recognize_google(audio)
                print("You said: " + text)

            except sr.UnknownValueError:
                print("Sorry, I could not understand the audio.")
            except sr.RequestError as e:
                print(f"Could not request results from the recognition service; {e}")
            except KeyboardInterrupt:
                print("Stopping the continuous listening...")
                break

    except KeyboardInterrupt:
        print("Exiting program.")
