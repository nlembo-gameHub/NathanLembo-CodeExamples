using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
using NightmaresClasses;
using NightmaresClasses.Biological;
using NightmaresClasses.Biological.Player;

public class Alert_State : StateMachineBehaviour
{
    TestController ai;
    NavMeshAgent navMesh;

    // OnStateEnter is called when a transition starts and the state machine starts to evaluate this state
    override public void OnStateEnter(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        ai = animator.GetComponent<TestController>();
    }

    // OnStateUpdate is called on each Update frame between OnStateEnter and OnStateExit callbacks
    override public void OnStateUpdate(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        ai.aiAgent.isStopped = false;
        if (ai.IsAggrevated() && ai.player != null && ai.playerIsDead != true)
        {
            ai.AggrevateNearbyEnemies();
            Vector3 direction = ai.player.transform.position - ai.transform.position;
            Quaternion rotation = Quaternion.LookRotation(direction);
            ai.transform.rotation = Quaternion.Lerp(ai.transform.rotation, rotation, 5f * Time.deltaTime);

            ai.aiAgent.speed = ai.maxSpeed;
            ai.timeSinceLastSawPlayer = 0;
            ai.aiAgent.enabled = true; //Enables the aiAgent
            if (Vector3.Distance(ai.transform.position, ai.player.transform.position) > ai.stoppingDistance)
            {
                ai.aiAgent.isStopped = false;
                ai.aiAgent.SetDestination(ai.player.transform.position); //Sets the AI's destination to the player's
            }
            else
            {
                ai.aiAgent.isStopped = true;
            }
            if (Vector3.Distance(ai.player.transform.position, ai.transform.position) < ai.attackDistance)
            {
                Debug.Log("Stuck in Alert in third if statement");
                if (ai.attackCooldown <= 0f)
                {
                    animator.SetBool("IsAlert", false);
                    animator.SetBool("IsAttacking", true);
                }
                else
                {
                    animator.SetBool("IsAlert", true);
                    animator.SetBool("IsAttacking", false);
                }

                Debug.Log("Can Attack Player");
            }
        }
        else if (ai.timeSinceLastSawPlayer < ai.suspicionTime)
        {
            //animator.SetTrigger("Suspicion");
            animator.SetBool("IsAttacking", false);
            animator.SetBool("IsAlert", false);
            animator.SetBool("IsSuspicious", true);
        }
        else if(ai.player == null || ai.playerIsDead == true)
        {
            animator.SetBool("IsAttacking", false);
            animator.SetBool("IsAlert", false);
            animator.SetBool("IsSuspicious", false);
            animator.SetBool("IsPatrolling", true);
            //animator.SetTrigger("Patrol");
        }
    }

    // OnStateExit is called when a transition ends and the state machine finishes evaluating this state
    override public void OnStateExit(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {

    }
}
