public static int findMaximumAlloyUnits(List<Integer> composition, List<Integer> stock, List<Integer> cost, int budget) {
        // Step 1: Calculate for each composition, how many alloy units can be produced.
        List<Integer> existAlloyUnits = new ArrayList<>();
        HashMap<Integer, Integer> alloyUnitsMap = new HashMap<>();
        HashSet<Integer> iterateSet = new HashSet<>();
        for (int i = 0; i < composition.size(); i++) {
            int alloyUnit = stock.get(i) / composition.get(i);
            existAlloyUnits.add(alloyUnit);
            alloyUnitsMap.put(i, alloyUnit);
            iterateSet.add(i);
        }

        // Step 2: Sort the existAlloyUnits and calculate budget
        Collections.sort(existAlloyUnits);
        System.out.println(existAlloyUnits);
        int count = 0;
        int newCost = 0;
//        System.out.println(existAlloyUnits);// 1,2,3
        while (true) {
            System.out.println("budget: " + budget + "  newCost: " + newCost + "  count: " + count);
            int units = existAlloyUnits.get(0);
            count = units;
            // 2.1 Mend the rest to meet the budget and calculate the cost
            HashSet<Integer> tempSet = new HashSet<>();
            int tempNewCost = newCost;
            for (int i: iterateSet) {
                // 2.1.1 Those with more numbers, dont need to think of it

                if (alloyUnitsMap.get(i) > units) {
                    continue;
                }
                System.out.println("Iterate for: " + i);
                // 2.1.2 Mend the difference and count a new cost
                int need = composition.get(i) - stock.get(i) % composition.get(i);
                budget -= need * cost.get(i);
                tempNewCost += composition.get(i) * cost.get(i);
                // 2.1.3 Remove the element from the set
                tempSet.add(i);
            }
            budget -= newCost;
            newCost = tempNewCost;
            // 2.1.4 Remove the element from the used set
            iterateSet.removeAll(tempSet);
            if (budget < 0) {
                return units;
            }
            count++;

            // 2.2 Count how many can be generated in this way
            if (existAlloyUnits.size() == 1) {
                // Skip here
                break;
            }
            int available = existAlloyUnits.get(1) - count;
            if (available*newCost > budget) {
                available = budget / newCost;
                return count + available;
            } else {
                count += available;
                budget -= available * newCost;
                existAlloyUnits.remove(0);
            }
        }
        System.out.println("budget: " + budget + "  newCost: " + newCost + "  count: " + count);

        // Step 3: Calculate the rest
        int num = budget / newCost;
        return count + num;

    }