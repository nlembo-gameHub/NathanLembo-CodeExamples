using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "New Conversation", menuName = "Conversation")]
public class Conversation : ScriptableObject
{
    public NPC leftSpeaker;
    public NPC rightSpeaker;
    public NPC currentSpeaker;
    public AudioSource voiceLineSource;
    public AudioClip[] voiceLines;
    public string[] npcLines;
    public string[] playerLines;
    public int npcIndex;
    public int playerIndex;
    public int conversationIndex;
}
