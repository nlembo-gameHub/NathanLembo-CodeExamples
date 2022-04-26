using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using NightmaresClasses;
using NightmaresClasses.Biological;
using NightmaresClasses.Utilities;
using UnityEngine.Playables;

public class DialogContainerPlayer : MonoBehaviour
{

    public GameObject[] dialogObjects;
    [SerializeField] private GameObject playerObj;
    [SerializeField] private GameObject dialogManager;
    private GameObject levelLoaderObj;
    private LevelLoader levelLoader;
    private DialogInteractionManager dialogManagerScript;
    private NightmarePlayer playerData;
    [SerializeField] GameObject cinematicObj;
    [SerializeField] GameObject dialogCamera;
    [SerializeField] GameObject cutsceneToActivate;
    [SerializeField] GameObject finalFightObj;
    [SerializeField] private bool isFinalCutscene;
    public int convoIndex = 0;
    public float transitionTime = 1f;
    public bool containerHasPlayed;
    public bool containerHasEnded;
    // Start is called before the first frame update
    void Start()
    {
        playerObj = GameObject.FindWithTag("Player");
        levelLoaderObj = GameObject.FindWithTag("Level Loader");
        dialogManager = GameObject.FindWithTag("DialogManager");
        if (playerObj != null)
        {
            Debug.Log("Is Starting");
           playerData = playerObj.GetComponent<NightmarePlayer>();
           levelLoader = levelLoaderObj.GetComponent<LevelLoader>();
           dialogManagerScript = dialogManager.GetComponent<DialogInteractionManager>();
           playerData.eyes.enabled = false;
           playerData.PlayerState = States.DUMMY;
            if(cinematicObj == null)
            {
                StartCoroutine(BeginScene(transitionTime));

            }
        }

    }

    private void Update()
    {
        if(isFinalCutscene)
        {
            if(containerHasEnded)
            {
                cutsceneToActivate.SetActive(true);
                finalFightObj.SetActive(true);
            }
        }
        if (cinematicObj != null)
        {
            if(containerHasPlayed == false)
            {
                StartCoroutine(BeginScene(transitionTime));
                containerHasPlayed = true;
            }
            else if (containerHasPlayed == true)
            {
                if (dialogObjects[convoIndex].GetComponent<DialogStarter>().conversationEnded == true && convoIndex < dialogObjects.Length - 1)
                {

                    convoIndex++;
                    StartDialogCutscene();
                    Cursor.lockState = CursorLockMode.Confined;
                    Cursor.visible = true;
                }
                else if (convoIndex == dialogObjects.Length - 1)
                {
                    //playerData.eyes.enabled = true;
                    gameObject.SetActive(false);
                    dialogCamera.SetActive(false);
                }
            }
        }
        else
        {
            if (dialogObjects[convoIndex].GetComponent<DialogStarter>().conversationEnded == true && convoIndex < dialogObjects.Length - 1)
            {
                convoIndex++;
                StartDialogCutscene();
            }
            else if (convoIndex == dialogObjects.Length - 1)
            {
                //playerData.eyes.enabled = true;
                
                dialogManager.GetComponent<DialogInteractionManager>().dialogPanel.SetActive(false);
                gameObject.SetActive(false);           
                if(dialogCamera != null)
                {
                    dialogCamera.SetActive(false);
                    containerHasEnded = true;
                }
                
            }
        }

    }

    IEnumerator BeginScene(float time)
    {
        yield return new WaitForSeconds(time);
        StartDialogCutscene();
    }

    private void StartDialogCutscene()
    {
        Debug.Log("Start Dialog Cutscene");
        if(dialogObjects[convoIndex].GetComponent<DialogStarter>().conversationStarted == false)
        {
            dialogObjects[convoIndex].GetComponent<DialogStarter>().SendConvoData();
        }
    }

    public void SkipCutscene()
    {
        convoIndex = dialogObjects.Length - 1;
    }
}
