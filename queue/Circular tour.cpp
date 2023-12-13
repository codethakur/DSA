int tour(petrolPump p[], int n)
{
    int start = 0;  // Starting point of the tour
    int end = 1;    // Next petrol pump to consider
    int curPetrol = p[start].petrol - p[start].distance;  // Petrol available at the starting point

    // Loop until we find a suitable starting point or determine it's not possible
    while (end != start || curPetrol < 0)
    {
        // If current petrol is not enough to reach the next pump
        // Move to the next pump and update the available petrol
        while (curPetrol < 0 && end != start)
        {
            curPetrol -= p[start].petrol - p[start].distance;
            start = (start + 1) % n;
            
            // If start becomes 0, it means we have tried all possible starting points and failed
            if (start == 0)
                return -1;
        }

        // Update the petrol available at the next pump and move to the next pump
        curPetrol += p[end].petrol - p[end].distance;
        end = (end + 1) % n;
    }

    // If the loop exited, we have found a starting point that satisfies the condition
    return start;
}
