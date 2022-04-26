using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using NightmaresClasses;
using NightmaresClasses.Biological;
using NightmaresClasses.Utilities;

public class DialogStarter : MonoBehaviour
{
    public GameObject dialogMenu;
    public Conversation convoSO;
    public bool conversationStarted;
    public bool conversationEnded;
    public bool forEndSceneOnly;
    [SerializeField] bool endsOtherDialogStarters;
    [SerializeField] bool activatesOtherDialogStarters;
    [SerializeField] bool startDialog;
    [SerializeField] bool hasPrompt;
    [SerializeField] GameObject promptBox;
    [SerializeField] GameObject[] otherDialogStartersToEnd;
    [SerializeField] GameObject[] otherDialogStartersToActivate;
    [SerializeField] NightmarePlayer playerScript;
    public DialogInteractionManager managerScript;
    Collider self_Collider;
    public GameObject playerObj;

    void Start()
    {
        conversationStarted = false;
        playerObj = GameObject.FindWithTag("Player");
        GameObject dialogManager = GameObject.FindWithTag("DialogManager");
        managerScript = dialogManager.GetComponent<DialogInteractionManager>();
        self_Collider = GetComponent<Collider>();
        if(playerObj != null)
        {
            playerScript = playerObj.GetComponent<NightmarePlayer>();
        }
    }

    private void Update()
    {
        playerObj = GameObject.FindWithTag("Player");
        GameObject dialogManager = GameObject.FindWithTag("DialogManager");
        managerScript = dialogManager.GetComponent<DialogInteractionManager>();
        if(forEndSceneOnly)
        {
            if (conversationEnded == true)
            {
                if (activatesOtherDialogStarters == true)
                {
                    for (int i = 0; i < otherDialogStartersToActivate.Length; i++)
                    {
                        Debug.Log("Activating " + otherDialogStartersToActivate[i].name);
                        otherDialogStartersToActivate[i].SetActive(true);

                    }
                }
            }
        }

        if(startDialog)
        {
            SendConvoData();
        }

        if(hasPrompt)
        {
            if(conversationEnded)
            {
                promptBox.SetActive(true);
                hasPrompt = false;
            }
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.gameObject.tag == "Player" && managerScript.inConversation != true)
        {
            playerObj = GameObject.FindWithTag("Player");
            conversationStarted = true;
            managerScript.conversation = convoSO;
            managerScript.npc = gameObject;
            managerScript.player = playerObj.GetComponent<NightmarePlayer>();
            managerScript.starter = this;
            Debug.Log("Starting Conversation");
            dialogMenu.SetActive(true);
            managerScript.BeginConversation();
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject.tag == "Player" && conversationEnded == true)
        {
            if(endsOtherDialogStarters == true)
            {
                for(int i = 0; i < otherDialogStartersToEnd.Length; i++)
                {
                    Debug.Log("Disabling " + otherDialogStartersToEnd[i].name);
                    otherDialogStartersToEnd[i].SetActive(false);
                }
            }
            if(activatesOtherDialogStarters && forEndSceneOnly == false)
            {
                for (int i = 0; i < otherDialogStartersToActivate.Length; i++)
                {
                    Debug.Log("Activating " + otherDialogStartersToActivate[i].name);
                    otherDialogStartersToActivate[i].SetActive(true);
                }
            }
            self_Collider.enabled = false;
        }
    }

    public void SendConvoData()
    {
        startDialog = false;
        playerObj = GameObject.FindWithTag("Player");
        managerScript.starter = this;
        conversationStarted = true;
        managerScript.conversation = convoSO;
        Debug.Log("Starting Conversation");
        dialogMenu.SetActive(true);
        managerScript.BeginConversation();
    }
}
