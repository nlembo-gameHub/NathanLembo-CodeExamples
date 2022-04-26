using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
using NightmaresClasses;
using NightmaresClasses.Biological;
using NightmaresClasses.Biological.Player;

public class Attack_State : StateMachineBehaviour
{
    TestController ai;
    NavMeshAgent navMesh;
    Entity playerStatus;
    // OnStateEnter is called when a transition starts and the state machine starts to evaluate this state
    override public void OnStateEnter(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        ai = animator.GetComponent<TestController>();
    }

    // OnStateUpdate is called on each Update frame between OnStateEnter and OnStateExit callbacks
    override public void OnStateUpdate(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        if(ai.player != null && ai.playerIsDead != true)
        {
            Debug.Log("Is in the Attack State");
            Vector3 direction = ai.player.transform.position - ai.transform.position;
            Quaternion rotation = Quaternion.LookRotation(direction);
            ai.transform.rotation = Quaternion.Lerp(ai.transform.rotation, rotation, 5f * Time.deltaTime);
            ai.timeSinceLastSawPlayer = 0;
            if (Vector3.Distance(ai.player.transform.position, ai.transform.position) < ai.attackDistance)
            {

                if (ai.attackCooldown <= 0f && ai.playerIsDead != true)
                {
                    animator.SetBool("IsAttacking", true);
                    animator.SetBool("IsAlert", false);
                    if (ai.player != null)
                    ai.StartCoroutine(AttackPlayer());
                }
                else
                {
                    animator.SetBool("IsAttacking", false);
                    animator.SetBool("IsAlert", true);
                }
            }
        }
        else
        {
            animator.SetBool("IsAttacking", false);
            animator.SetBool("IsAlert", false);
            animator.SetBool("IsPatrolling", true);
        }
       
    }

    // OnStateExit is called when a transition ends and the state machine finishes evaluating this state
    override public void OnStateExit(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {

    }

    IEnumerator AttackPlayer()
    {

        //This is all to temporarily makesure that the enemy can attack, can be delt damage, and that the player is firing up their aggro
        Debug.Log("Deal Damage");
        //Call the Player Health Script to deal damage to the player
        if (ai.playerIsDead != true)
        {
            DamageInfo aiDamage = new DamageInfo(ai.attackDamage, ai.attackType);
            if(ai.player != null)
            ai.playerStats.Hurt(ai, aiDamage);
        }
        ai.attackCooldown = 5f;
        //Will need to be called in collision object when player deals damage
        yield return new WaitForSeconds(1.2f);
        ai.aiAgent.enabled = true;
    }
}
