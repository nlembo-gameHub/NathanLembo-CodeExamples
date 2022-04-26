using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using NightmaresClasses.Biological;
using NightmaresClasses.Utilities;

public class DialogInteractionManager : MonoBehaviour
{
    //UI Assets
    public Image portrait;
    public TextMeshProUGUI fullName;
    public TextMeshProUGUI textDisplay;
    public GameObject continueButton;
    public GameObject skipButton;
    public GameObject dialogPanel;
    [SerializeField] private GameObject phoneUI;
    //Scriptable Objects
    public Conversation conversation;
    public Conversation currentCharacter;
    //Game Objects
    public DialogStarter starter;
    public GameObject npc;
    //Local Variables
    public float typingSpeed;
    public int playerIndex = 0;
    public int npcIndex = 0;
    public int currentConvoIndex;
    public int voiceLineIndex;
    public string[] messages;
    public NightmarePlayer player;
    GameObject playerObj;
    public bool inConversation;
    public bool conversationEnded;

    private void Start()
    {
        npc = GameObject.FindGameObjectWithTag("NPC");
        playerObj = GameObject.FindWithTag("Player");
        if (npc != null)
        {
            starter = npc.GetComponent<DialogStarter>();
        }
    }

    public void BeginConversation()
    {
        if (starter.conversationStarted == true)
        {
            inConversation = true;
            playerObj = starter.playerObj;
            player = playerObj.GetComponent<NightmarePlayer>();
            player.GetComponent<HUD>().showUI = false;
            phoneUI = GameObject.FindWithTag("PhoneCanvas");
            if(phoneUI != null)
            {
                if(phoneUI.GetComponent<PhoneUIInteract>()._openPhone)
                phoneUI.GetComponent<PhoneUIInteract>().ClosePhoneInUIEvent();
            }
            player.PlayerState = States.DUMMY;
            currentCharacter = conversation;
            currentCharacter.currentSpeaker = conversation.leftSpeaker;
            fullName.text = conversation.leftSpeaker.npcName;
            fullName.color = conversation.leftSpeaker.npcNameColor;
            portrait.sprite = conversation.leftSpeaker.npcSprite;
            messages = conversation.npcLines;
            conversation.voiceLineSource = GetComponent<AudioSource>();
            conversation.voiceLineSource.clip = conversation.voiceLines[voiceLineIndex];
            conversation.voiceLineSource.Play();
            skipButton.SetActive(false);
            continueButton.SetActive(false);
            StopAllCoroutines();
            StartCoroutine(TypeLine());
        }
    }

    private void Update()
    {
        
        if (starter.conversationStarted == true && playerObj != null)
        {
            if (textDisplay.text == messages[currentConvoIndex])
            {
                continueButton.SetActive(true);
                skipButton.SetActive(true);
            }
        }
    }

    IEnumerator TypeLine()
    {
        foreach (char letter in messages[currentConvoIndex].ToCharArray())
       {
           textDisplay.text += letter;
           yield return new WaitForSeconds(typingSpeed);
       }
    }

    public void NextSentence()
    {
        continueButton.SetActive(false);
        skipButton.SetActive(false);
        if (voiceLineIndex < conversation.voiceLines.Length - 1)
        {
            voiceLineIndex++;
            conversation.voiceLineSource.clip = conversation.voiceLines[voiceLineIndex];
            conversation.voiceLineSource.Play();
        }
        if (currentConvoIndex < messages.Length - 1)
        {
            SetCharacter();
            textDisplay.text = "";
            StartCoroutine(TypeLine());
        }
        else
        {
            EndDialog();
        }
    }

    private void EndDialog()
    {
        textDisplay.text = "";
        continueButton.SetActive(false);
        skipButton.SetActive(false);
        conversation.voiceLineSource.Stop();
        npcIndex = 0;
        playerIndex = 0;
        currentConvoIndex = 0;
        voiceLineIndex = 0;
        dialogPanel.SetActive(false);
        starter.conversationStarted = false;
        starter.conversationEnded = true;
        conversation = null;
        currentCharacter = null;
        npc = null;
        inConversation = false;
        conversationEnded = true;
        player.GetComponent<HUD>().showUI = true;
        player.PlayerState = States.PATROL;
    }

    public void SetCharacter()
    {
        if(currentCharacter.currentSpeaker == conversation.leftSpeaker)
        {
            npcIndex++;
            currentConvoIndex = playerIndex;
            currentCharacter.currentSpeaker = conversation.rightSpeaker;
            fullName.text = conversation.rightSpeaker.npcName;
            fullName.color = conversation.rightSpeaker.npcNameColor;
            portrait.sprite = conversation.rightSpeaker.npcSprite;
            messages = conversation.playerLines;
        }
        else if(currentCharacter.currentSpeaker == conversation.rightSpeaker)
        {
            playerIndex++;
            currentConvoIndex = npcIndex;
            currentCharacter.currentSpeaker = conversation.leftSpeaker;
            fullName.text = conversation.leftSpeaker.npcName;
            fullName.color = conversation.leftSpeaker.npcNameColor;
            portrait.sprite = conversation.leftSpeaker.npcSprite;
            messages = conversation.npcLines;
        }
    }

    public void SkipDialog()
    {
        EndDialog();
    }

}
