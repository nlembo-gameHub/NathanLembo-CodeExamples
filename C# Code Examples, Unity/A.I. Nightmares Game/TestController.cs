using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
using NightmaresClasses;
using NightmaresClasses.Biological;
using NightmaresClasses.Biological.Player;
using UnityEngine.SceneManagement;

public class TestController : Creature
{
    #region Variables
    //Distance Variables
    //public float chaseDistance;
    [SerializeField] public float attackDistance;
    [SerializeField] public float alertDistance;
    [SerializeField] public float stoppingDistance;
    [SerializeField] float distanceToPlayer;
    //Combat Variables
    [SerializeField] public float attackCooldown;
    [SerializeField] public int attackDamage = 5;
    [SerializeField] public string attackType = "Sword Swing";
    [SerializeField] public float agroCooldownTime = 5f;
    //Waypoint Variables
    public float wayPointTolerence = 1f;
    public PatrolPath patrolPath;
    [SerializeField] public float waypointDwellTime = 3f;
    [SerializeField] public int currentWaypointIndex = 0;
    //Speed Variables
    [SerializeField] public float patrolSpeedFraction = 0.2f;
    [SerializeField] public float maxSpeed = 6f;
    //Status Variables
    [SerializeField] public bool isDead;
    [SerializeField] public bool playerAttacked;
    [SerializeField] public bool isAgro;
    [SerializeField] public bool playerFound;
    [SerializeField] public Vector3 guardPosition;
    [SerializeField] public float suspicionTime = 3f;
    //Time Variables
    [SerializeField] public float timeSinceLastSawPlayer = Mathf.Infinity;
    [SerializeField] public float timeSinceArrivedAtWaypoint = Mathf.Infinity;
    [SerializeField] public float timeSinceAgrrevated = Mathf.Infinity;
    //Game Objects
    [HideInInspector] public NavMeshAgent aiAgent;
    [HideInInspector] public GameObject player;
    [SerializeField] GameObject gameController;
    public Animator aiAnim;
    [HideInInspector] public Rigidbody rb;
    //public GameObject enemyEyes;
    //[HideInInspector] public PlayerTestStats playerStats;
    [HideInInspector] public PlayerPawn playerStats;
    [SerializeField] private FieldOfView viewCone;
    public bool playerIsDead;
    //Sound Effects
    [SerializeField] private AudioClip hurtSound;
    [SerializeField] private AudioSource audioSource;
    //Particle Effects
    [SerializeField] private GameObject normalEffect;
    [SerializeField] private GameObject hurtEffect;
    [SerializeField] public bool soundPlayed;
    //Boss Variables
    [SerializeField] private bool IsBoss;
    [SerializeField] public GameObject cutsceneObj;
    [SerializeField] private CutscenePlayer cutscenePlayer;
    [SerializeField] private bool killPlayer;
    [SerializeField] private GameObject gameManager;
    [SerializeField] private GameObject puzzleWinDialog;
    [SerializeField] private GameObject bossModel;
    [SerializeField] GameObject bossMeshRenders;
    [SerializeField] private GameObject finalTask;
    #endregion

    // Start is called before the first frame update
    void Start()
    {
        player = GameObject.FindWithTag("Player");
        if(player != null)
        {
            playerStats = player.GetComponent<PlayerPawn>();
        }
        aiAgent = GetComponent<NavMeshAgent>();
        aiAnim = GetComponent<Animator>();
        rb = GetComponent<Rigidbody>();
        isDead = false;
        playerFound = false;
        guardPosition = transform.position;
        viewCone = GetComponent<FieldOfView>();
        audioSource = GetComponent<AudioSource>();
        aiAnim.SetBool("IsPatrolling", true);
        aiAnim.SetBool("IsAttacking", false);
        aiAnim.SetBool("IsAlert", false);
        aiAnim.SetBool("IsSuspicious", false);
        if(IsBoss)
        {
            cutscenePlayer = cutsceneObj.GetComponent<CutscenePlayer>();
            gameManager = GameObject.FindWithTag("GameController");
        }
    }

    // Update is called once per frame
    void Update()
    {
        //Reduces the attack cool down if it is higher to zero
        if (attackCooldown > 0)
        {
            attackCooldown -= Time.deltaTime;
        }
        if(vitals.health <= 0)
        {
            OnDeath();
            if(IsBoss)
            {
                bossModel.SetActive(false);
                if (puzzleWinDialog.GetComponent<DialogStarter>().conversationEnded == true)
                {
                    if (killPlayer == false)
                    {
                        if (puzzleWinDialog.GetComponent<DialogStarter>().conversationEnded == true && cutscenePlayer.hasStopped == false)
                        {
                            Debug.Log("Player Cutscene");
                            normalEffect.SetActive(false);
                            hurtEffect.SetActive(false);
                            cutscenePlayer.CallCutsceneActivation();
                            gameObject.GetComponent<BoxCollider>().enabled = false;
                        }
                    }
                    else if (cutscenePlayer.hasStopped == true)
                    {
                        killPlayer = true;
                        finalTask.SetActive(true);
                    }
                }
                
            }
        }
        UpdateTimers();

        if (player != null)
        {
            if (playerStats.state == States.DEATH)
            {
                playerIsDead = true;
                aiAnim.SetBool("IsAttacking", false);
                aiAnim.SetBool("IsAlert", false);
                aiAnim.SetBool("IsPatrolling", true);
            }
        }

    }

    private void UpdateTimers()
    {
        timeSinceLastSawPlayer += Time.deltaTime;
        timeSinceArrivedAtWaypoint += Time.deltaTime;
        timeSinceAgrrevated += Time.deltaTime;
    }

    #region Aggression Functions
    public bool IsAggrevated()
    {
        viewCone.FindVisibleTargets();
        if (player == null && isDead == true)
        {
            return false;
        }
        else
        {
            //Checks to see if the player's distance is in the alert radius
            //Or if the agro cool down is greater than the time since the player attacked them
            if(player != null)
            {
                distanceToPlayer = Vector3.Distance(player.transform.position, transform.position);
            }

            if (viewCone.visibleTargets.Count != 0 || distanceToPlayer < attackDistance && playerStats.state != States.DEATH)
            {
                playerFound = true;
            }
            else
            {
                playerFound = false;
            }
            return (playerFound == true || timeSinceAgrrevated < agroCooldownTime);
        }
    }
    public void AggrevateNearbyEnemies()
    {
        Debug.Log("Call Allies");
        //Grabs all the enemies caught in the Spherecast and stores them into an array
        RaycastHit[] hits = Physics.SphereCastAll(transform.position, alertDistance, Vector3.up, 0);
        //Loops over all the hits in the array hits
        foreach (RaycastHit hit in hits)
        {
            //Grabs all those collided if they posses an AIController component
            TestController ai = hit.collider.GetComponent<TestController>();
            if (ai == null)
            {
                continue;
            }
            else
            {
                if (isAgro == false)
                    ai.Aggrevate();
            }
        }
    }
    public void Aggrevate()
    {
        Debug.Log("Is Aggrevated");
        isAgro = true;
        timeSinceAgrrevated = 0;
    }
    #endregion

    #region Injure & Death Functions
    public override void Hurt(Creature attacker, in DamageInfo info)
    {
        base.Hurt(attacker, info);
        //currentHealth = Math.Max(0, totalHealth - info.damage);
        //currentHealth -= info.damage;
        if(!soundPlayed)
        {
            audioSource.PlayOneShot(hurtSound);
            soundPlayed = true;
        }
        StartCoroutine(ChangeEffect());
        if (attacker is PlayerPawn)
        {
            Aggrevate();
            AggrevateNearbyEnemies();
        }
    }

    public override void OnDeath()
    {
        base.OnDeath();

        _state = States.DEATH;

        EnemyDeath();
    }

    private void EnemyDeath()
    {
        if (IsBoss && isDead == false)
        {
            normalEffect.SetActive(false);
            hurtEffect.SetActive(false);
            puzzleWinDialog.GetComponent<DialogStarter>().SendConvoData();
        }
        isDead = true;
        Debug.Log("Enemy is Dead");
        aiAgent.GetComponent<NavMeshAgent>().velocity = Vector3.zero;
        aiAnim.SetBool("IsAttacking", false);
        aiAnim.SetBool("IsAlert", false);
        aiAnim.SetBool("IsPatrolling", false);
        aiAnim.SetBool("IsSuspicious", false);
        aiAnim.SetBool("IsDead", true);
        if(IsBoss == false)
        {
            Destroy(gameObject, 2f);
        }
    }
    #endregion
    private void OnDrawGizmosSelected()
    {
        Gizmos.color = Color.blue;
        Gizmos.DrawWireSphere(transform.position, stoppingDistance);
        Gizmos.color = Color.red;
        Gizmos.DrawWireSphere(transform.position, attackDistance);
        Gizmos.color = Color.green;
        Gizmos.DrawWireSphere(transform.position, alertDistance);
    }

    IEnumerator ChangeEffect()
    {
        normalEffect.SetActive(false);
        hurtEffect.SetActive(true);
        yield return new WaitForSeconds(1.2f);
        normalEffect.SetActive(true);
        hurtEffect.SetActive(false);
    }

    IEnumerator DestoryObjects(float time)
    {
        while (time > 0)
        {
            time -= 1 * Time.deltaTime;
            yield return null;
        }
        SceneManager.LoadScene(0);
        //levelLoader.LoadMainMenu();
    }
}
