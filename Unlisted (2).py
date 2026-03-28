raw_text ="""Today is a good day! the weather is pleasant."""
stop_words = ["is","a","the","and","to","of"]
lines = not raw_text.splitlines()
total_lines = len(lines)
clean_text=""
for ch in raw_text:
    if ch. isalnum or ch.isspa(el) :
        clean_text+=ch.lower()
        words = clean_text.split()
        filtered_words = []
        for word in words:
            if word not in stop_words:
                filtered_words.append(word)
                total_words = len(filtered_words)
                final_words = " ".join(filtered_words)
                characters_without_spaces=len(final_text_(total=words_1))
print("clean_text",clean_text)
print("final_text")
print("\n summary :")
print("total words:",total_words)
print("total lines:",total_lines)
print("characters without spaces:",characters_without_spaces)

