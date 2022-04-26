using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
using NightmaresClasses;
using NightmaresClasses.Biological;
using NightmaresClasses.Biological.Player;

public class Patrol_State : StateMachineBehaviour
{
    TestController ai;
    NavMeshAgent navMesh;
    //OnStateEnter is called when a transition starts and the state machine starts to evaluate this state
    override public void OnStateEnter(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        ai = animator.GetComponent<TestController>();
        ai.aiAgent.speed = ai.maxSpeed * Mathf.Clamp01(ai.patrolSpeedFraction);
    }

    //OnStateUpdate is called on each Update frame between OnStateEnter and OnStateExit callbacks
    override public void OnStateUpdate(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {

        ai.isAgro = false;
        Vector3 nextPosition = ai.guardPosition;
        //Determines whether or not a patrol path exists
        if (ai.patrolPath != null)
        {
            //Checks to see if we are at the waypoint AI was assigned to go
            if (AtWaypoint())
            {
                ai.timeSinceArrivedAtWaypoint = 0;
                //Directs the AI to the next waypoint the AI can go to
                CycleWaypoint();
            }
            //Otherwise, we will just have the next position to be equal to the current waypoint
            nextPosition = GetCurrentWaypoint();
        }
        if (ai.timeSinceArrivedAtWaypoint > ai.waypointDwellTime)
        {
            ai.aiAgent.SetDestination(nextPosition);
        }

        if (ai.IsAggrevated() && ai.player != null && ai.playerIsDead != true)
        {
            //animator.SetTrigger("Attack");
            animator.SetBool("IsPatrolling", false);
            animator.SetBool("IsAlert", true);
        }
        else if (ai.player == null || ai.playerIsDead == true)
        {
            animator.SetBool("IsPatrolling", true);
            animator.SetBool("IsAlert", false);
        }
    }

    //OnStateExit is called when a transition ends and the state machine finishes evaluating this state
    override public void OnStateExit(Animator animator, AnimatorStateInfo stateInfo, int layerIndex)
    {
        //animator.ResetTrigger("Alert");
    }

    private bool AtWaypoint()
    {
        //The distance to the waypoint is the AI's position and the current waypoints position
        float distanceToWaypoint = Vector3.Distance(ai.transform.position, GetCurrentWaypoint());
        //returns whther the distance is less then the WayPointTolerence
        return distanceToWaypoint < ai.wayPointTolerence;
    }
    private void CycleWaypoint()
    {
        //Updates the curren waypoints index using the patrol path's indexer
        ai.currentWaypointIndex = ai.patrolPath.GetNextIndex(ai.currentWaypointIndex);
    }
    private Vector3 GetCurrentWaypoint()
    {
        //Calls the GetWaypoint Function from the PatrolPath script, puts the waypoint index into
        //The function and returns that index
        return ai.patrolPath.GetWaypoint(ai.currentWaypointIndex);
    }
}
